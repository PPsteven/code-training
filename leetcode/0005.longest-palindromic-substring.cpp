#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // init
        for (int i=0; i<n; i++) {
            dp[i][i] = true;
        }
        int start = 0;
        int max_len = 1;
        for (int r=1; r<n; r++) {
            for (int l=0; l<r; l++) {
                // corner case: r=l+1
                if (s[l] == s[r] && (l==r-1 || dp[l+1][r-1])) {
                    dp[l][r] = true;
                    if (r-l+1>max_len) {
                        max_len = r-l+1;
                        start = l;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};

int main() {
    auto ans = Solution().longestPalindrome("babbad");
    cout << ans << endl;
    return 0;
}


// dp[i][j] i, j 字符串位置 value 是否回文
// abcacba => abcacb + a
// s[i] == s[j] && dp[i+1][j-1] => dp[i][j] = true

// corner case: bb index out of bound
