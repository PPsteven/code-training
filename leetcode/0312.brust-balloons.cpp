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
    int maxCoins(vector<int>& nums) {
        const int n = nums.size() + 2;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        nums.insert(nums.begin(), 1);
        nums.push_back(1);


        for (int w=2; w<n; w++) {
            for (int i=0; i<n-w; i++) {
                for (int j=i+1; j<i+w; j++) {
                    dp[i][i+w] = max(dp[i][i+w],
                       nums[i]*nums[j]*nums[i+w] + dp[i][j] + dp[j][i+w]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    vector<int> nums = {3,1,5,8};
    auto ans = Solution().maxCoins(nums);
    cout << ans << endl;
    return 0;
}
