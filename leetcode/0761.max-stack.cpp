#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

// 根据题意，在popMax的时候，若是存在栈顶元素不是最大值时
// 打破了栈先进后出的规律，官方题解使用双栈去解决
// 我认为这里用栈比较多余，直接用vector即可
class MaxStack {
public:
    vector<int> st;
    stack<int> max_st;

    MaxStack() {
        max_st.push(INT_MIN);
    }

    void push(int x) {
        st.push_back(x);
        max_st.push(max(x, max_st.top()));
    }

    int pop() {
        int v = st[st.size()-1];
        st.pop_back();
        max_st.pop();
        return v;
    }

    int top() {
        return st[st.size()-1];
    }

    int peekMax() {
        return max_st.top();
    }

    int popMax() {
        int max_value = max_st.top();
        int i; int j;
        for (i=st.size()-1; i>=0; i--){
            // 最大值已发生改变，所有的max_st都要重新生成
            max_st.pop();
            if (st[i] == max_value) {
                st.erase(st.begin()+i);
                break;
            }
        }
        for (int j=i; j<st.size(); j++) {
            max_st.push(max(max_st.top(), st[j]));
        }
        return max_value;
    }
};

// 双端队列+ 平衡二叉树


// 平衡二叉树的数据结构使用cpp的map库实现
// map 为key有序的映射表，底层使用红黑树实现
// multimap vs map: 支不支持key重复
// unordered_map vs map: unordered_map 使用哈希表
// reference: https://leetcode.cn/problems/max-stack/solution/lian-xi-shi-yong-c-zhuan-shu-de-multimap-shu-ju-ji/
class MaxStack2 {
public:
    // list 底层为双端链表
    // multimap 底层为红黑树
    list<int> l;
    multimap<int, list<int>::iterator> mp;

    MaxStack2() {
    }

    void push(int x) {
        l.push_back(x);
        // 节点的“指针”存入树
        mp.insert({x, --l.end()});
    }

    int pop() {
        auto last_it = --l.end();
        int ans = *last_it;
        auto removed_it = --mp.upper_bound(ans);
        mp.erase(removed_it);
        l.pop_back();
        return ans;
    }

    int top() {
        return l.back();
    }

    int peekMax() {
        return mp.rbegin()->first;
    }

    int popMax() {
        auto last_it = --mp.end();
        int ans = *last_it->second;
        mp.erase(last_it);
    }
};
