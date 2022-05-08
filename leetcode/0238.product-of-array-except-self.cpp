#include <vector>
#include <iostream>
using namespace std;

// Tips: 左右乘积列表
// nums = [1, 2, 3, 4]
// left = [1, 2, 6, 24]
// right = [24, 24 , 12, 4]
// ans[i] = left[i-1] * right[i+1], 越界算1
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> ans(n);

        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i];
            right[n-i-1] = right[n-i] * nums[n-i-1];
        }

        int l, r;
        for (int i=0; i<n; i++) {
            if (i == 0) {
                l = 1;
            } else {
                l = left[i-1];
            }

            if (i == n - 1) {
                r = 1;
            } else {
                r = right[i+1];
            }

            ans[i] = l * r;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = Solution().productExceptSelf(nums);
    for (auto x: ans) {
        cout << x << ' ' << endl;
    }
    cout << endl;
    return 0;
}
