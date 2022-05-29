#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    stack<int> st;

    int evalRPN(vector<string>& tokens) {
        int a; int b;
        for (int i=0; i<tokens.size(); i++) {
            auto token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                b = st.top(); st.pop();
                a = st.top(); st.pop();
                st.push(cal(a, b, token[0]));
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }

    int cal(int a, int b, char c) {
        switch (c) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        return 0;
    }
};

int main() {
    vector<string> tokens = {"2","1","+","3","*"};
    auto ans = Solution().evalRPN(tokens);
    cout << ans << endl;
    return 0;
}
