#include <algorithm>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0; int r = 0; int s = 0;
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            l = i + 1;
            r = n - 1;
            while (l < r) {
                s = nums[i] +nums[l] + nums[r];
                // improvement tip
                if (s == target) {
                    return target;
                } else if (s > target) {
                    r--;
                } else {
                    l++;
                }
                if (abs(s - target) < abs(ans - target)) {
                    ans = s;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int ans = Solution().threeSumClosest(nums, 1);
    cout << ans << endl;
    return 0;
}
