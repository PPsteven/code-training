#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int t1;int t2;
        for (int i=0; i<ops.size(); i++) {
            if (ops[i] == "C") {
                st.pop();
            } else if (ops[i] == "D") {
                st.push(st.top() * 2);
            } else if (ops[i] == "+") {
                t1 = st.top(); st.pop();
                t2 = st.top();
                st.push(t1);
                st.push(t1 + t2);
            } else {
                st.push(stoi(ops[i]));
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top(); st.pop();
        }
        return ans;
    }
};

int main() {
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    int ans = Solution().calPoints(ops);
    cout << ans << endl;
    return 0;
}
