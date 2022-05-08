#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

// case 0: ..) => dp[i] = 0
// case 1: ...() => dp[i] = dp[i-2] + 2
// case 2: ..((..)) =>
//      s[i-dp[i-dp[i-1]-1]] = '(' then
//      dp[i] = dp[i-dp[i-1]-2] + dp[i-1] + 2
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        int ans=0;
        for (int i=1; i<n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    int tmp = 0;
                    if (i >= 2) {
                        tmp = dp[i-2];
                    }
                    dp[i] = tmp + 2;
                } else if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                        int tmp = 0;
                        if (i-dp[i-1]-2>=0) {
                            tmp = dp[i-dp[i-1]-2];
                        }
                        dp[i] = tmp + dp[i-1] + 2;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};


int main() {
    int ans = Solution().longestValidParentheses("(())");
    cout << ans << endl;
    return 0;
}
