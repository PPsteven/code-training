#include <stack>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c: s) {
            switch (c) {
                case '(':
                    st.push(')');
                    break;
                case '[':
                    st.push(']');
                    break;
                case '{':
                    st.push('}');
                    break;
                default:
                    if (!st.empty() && st.top() == c) {
                        st.pop();
                    } else {
                        return false;
                    }
            }
        }
        return st.empty();
    }
};

int main() {
    bool ans = Solution().isValid("[");
    cout << ans << endl;
    return 0;
}
