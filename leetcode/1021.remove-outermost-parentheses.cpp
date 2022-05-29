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
    string removeOuterParentheses(string s) {
        const int n = s.length();
        string ans;
        int level = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                level++;
                if (level == 1) {
                    continue;
                }
                ans += s[i];
            } else if (s[i] == ')') {
                level--;
                if (level == 0) {
                    continue;
                }
                ans += s[i];
            }
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().removeOuterParentheses("(())()");
    cout << ans << endl;
    return 0;
}
