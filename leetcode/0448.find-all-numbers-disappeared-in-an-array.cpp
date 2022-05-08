#include <vector>
#include <iostream>
using namespace std;

// Solution 1: inplace modify nums, put the number into their right pos
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int p;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (i+1 == nums[i]) {
                continue;
            }
            p = nums[i];
            nums[i] = -1;
            while (p > 0 && p != nums[p - 1]) {
                int tmp = nums[p-1];
                nums[p-1] = p;
                p = tmp;
            }
        }

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == -1) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

// Solution 2: add n to their index place, and by nums[i] % n to get right index
// so then number <= n is the answer.

// Solution 3: reverse sign to their index place, and by abs(nums[i]) to get right index
// so when number < 0 is the answer.

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    // vector<int> nums = {1, 1};
    auto ans = Solution().findDisappearedNumbers(nums);
    // for (int i =0; i< ans.size();i++) {
        // cout << ans[i] << ' ';
    // }
    // cout << endl;
    return 0;
}
