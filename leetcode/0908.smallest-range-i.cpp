#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minv = nums[0];
        int maxv = nums[0];
        for (int i=1; i<nums.size();i++) {
            if (nums[i] > maxv) {
                maxv = nums[i];
            }
            if (nums[i] < minv) {
                minv = nums[i];
            }
        }
        return max(0, maxv - minv - k * 2);
    }
};

int main() {
    vector<int> nums = {1, 3, 10};
    int target = 2;
    int ans = Solution().smallestRangeI(nums, target);
    cout << ans << endl;
}
