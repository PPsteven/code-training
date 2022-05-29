#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// .. pop if stack is not empty
// . do nothing
// "" do nothing
// else push into stack
class Solution {
public:
    vector<string> split(string s) {
        vector<string> ans;
        string tmp = "";
        for (char &c : s) {
            if (c == '/') {
                ans.push_back(tmp);
                tmp.clear();
            } else {
                tmp += c;
            }
        }
        if (tmp.length()>0) {
            ans.push_back(tmp);
        }
        return ans;
    }

    string simplifyPath(string path) {
        stack<string> st;
        auto paths = split(path);
        for (int i=0; i<paths.size(); i++) {
            if (paths[i] == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (paths[i] != "." && paths[i] != "") {
                st.push(paths[i]);
            }
        }
        // special case
        if (st.empty()) {
            return "/";
        }
        string ans;
        while (!st.empty()) {
            ans = '/' + st.top() + ans; st.pop();
        }
        return ans;
    }
};

int main() {
    string ans = Solution().simplifyPath("/a/./b/.//../c/");
    cout << ans << endl;
    return 0;
}
