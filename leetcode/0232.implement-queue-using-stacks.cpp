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

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            load_data();
        }
        int ans = st2.top(); st2.pop();
        return ans;
    }

    int peek() {
        if (st2.empty()) {
            load_data();
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }

    void load_data() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }
};
