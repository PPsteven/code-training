#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// DP
// dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[j]]
// best answer dp[n-1][target]
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    }
};

int main() {
    vector<int> nums = {1, 1};
    auto ans = Solution().findTargetSumWays(nums, 0);
    cout << ans << endl;
    return 0;
}
