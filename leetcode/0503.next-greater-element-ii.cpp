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

// 单调栈+循数组
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        // 最多向后找n-1次，第n个是自己
        for (int i=0; i<n+n-1; i++) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,4,3};
    auto ans = Solution().nextGreaterElements(nums);
    for (int x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
