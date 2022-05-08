#include <iostream>
#include <vector>
using namespace std;

// DP
// f(1101) -> 1 + f(101)
class Solution {
public:
    vector<int> countBits(int n) {
        if (n==0) {return {0};}
        if (n==1) {return {0, 1};}
        vector<int> dp(n+1);
        dp[0] = 0; dp[1] = 1;
        int bit = 1;
        for (int i=2;i<=n;i++) {
            while (bit <= i) { bit = bit << 1;}
            dp[i] = 1 + dp[i - (bit>>1)];
        }
        return dp;
    }
};


int main() {
    auto ans = Solution().countBits(8);
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    cout << (2 << 1) << endl;
    return 0;
}
