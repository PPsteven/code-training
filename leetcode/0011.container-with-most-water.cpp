#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            // 短板向内移动
            if (height[l] < height[r]) {
                ans = max(ans, (r - l) * min(height[l], height[r]));
                l++;
            } else {
                ans = max(ans, (r - l) * min(height[l], height[r]));
                r--;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    int ans = Solution().maxArea(nums);
    cout << ans << endl;
    return 0;
}
