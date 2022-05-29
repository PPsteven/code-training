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

// 不能用摩尔投票法，本题数字没有超过N/2
// 用间隔法
// 1 2 3 1
// 两个相同数字的间隔不可能超过2，只要检查
// nums[i] 是否等于 nums[i-1], num[i-2], nums[i-3]
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int n = nums.size();
        // 根据题意，n >= 4
        for (int i=2; i<n; i++) {
            if ((i>=1 && nums[i]==nums[i-1]) ||
                (i>=2 && nums[i]==nums[i-2]) ||
                (i>=3 && nums[i] ==nums[i-3])) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums={1,2,3,3};
    auto ans = Solution().repeatedNTimes(nums);
    cout << ans << endl;
    return 0;
}
