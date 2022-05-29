#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Solution {
public:
    // Solution1: Stack
    // 从右向左依次入栈, 将正负结果都暂存栈中，直至碰到T或F
    // 如 T?T?2:3:3 = T?(T?2:3):3
    // stack: 3 3 2 => 3 2 => 2  可以发现栈顶的两个元素分别存储正负结果
    // Key: 从右向左入栈
    string parseTernary(string expression) {
        const int n = expression.length();
        stack<char> st;
        for (int i=n-1; i>=0; i--) {
            if ((expression[i] == 'T' || expression[i] == 'F') &&
                    !st.empty() && st.top()=='?') {
                st.pop();
                char a = st.top(); st.pop();
                st.pop(); // 弹出:
                char b = st.top(); st.pop();
                if (expression[i] == 'T') {
                    st.push(a);
                } else {
                    st.push(b);
                }
            } else {
                st.push(expression[i]);
            }
        }
        string ans;
        ans += st.top();
        return ans;
    }

    // Solution2: 递归法
    // 递归很多情况下与栈可以等价
    // 对于本题，需要匹配到正确的运算法? :
    // T?T?2:3:3  第一个? 应与最后一个: 匹配上
    string parseTernary2(string expression) {
        return helper(expression, 0, expression.size());
    }

    // 计算s[i:j] 中的答案
    string helper(string s, int i, int j) {
        if (s[i+1] == '?') {
            int check_level = 1;
            for (int k=i+2; k<j; k++) {
                if (s[k] == '?') {
                    check_level++;
                } else if (s[k] == ':'){
                    check_level--;
                    if (check_level==0) { // 找到对应的:
                        if (s[i] == 'T') {
                            return helper(s, i+2, k); // ? 到: 区间查找
                        } else {
                            return helper(s, k+1, j); // : 到j
                        }
                    }
                }
            }
        } else {
            return string(1, s[i]);
        }
        return "";
    }
};

int main() {
    auto ans = Solution().parseTernary2("T?F?4:5:3");
    cout << ans << endl;
    return 0;
}
