#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// Case nums are in range [1, n], and each integer appears once or twice
// so we have to use this condition
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<nums.size();i++) {
            nums[(nums[i]-1) % n]= nums[(nums[i]-1)%n] + n;
        }

        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 2 * n) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    auto ans = Solution().findDuplicates(nums);
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}

// -4 -3 2 7 -8 -2 -3 -1
