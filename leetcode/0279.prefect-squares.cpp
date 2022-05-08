#include <cstdio>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);

        dp[0] = 0;
        dp[1] = 1;

        for (int i=2; i<=n; i++) {
            for (int j=1; j<=int(sqrt(i)); j++) {
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
       }
        return dp[n];
    }
};

int main() {
    int ans = Solution().numSquares(12);
    printf("ans: %d", ans);
    return 0;
}
