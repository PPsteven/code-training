// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
// Return any array that satisfies this condition.

// Example 1:
// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
//
// Example 2:
// Input: nums = [0]
// Output: [0]

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] % 2 == 1) {
                swap(nums, l, r);
                r--;
            } else {
                l++;
            }
        }
        return nums;
    }

    void swap(vector<int>& nums, int l, int r) {
        int temp;
        temp = nums[r];
        nums[r] = nums[l];
        nums[l] = temp;
    }
};


int main() {
    vector<int> input = {3, 1, 2, 4};
    vector<int> output = Solution().sortArrayByParity(input);
    for (int i=0; i<output.size(); i++) {
        cout << output[i] << " ";
    }
    cout <<endl;
    return 0;
}
