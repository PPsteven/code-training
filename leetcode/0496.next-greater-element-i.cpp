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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i=0; i<nums2.size(); i++) {
            if (st.empty() || st.top() < nums2[i]) {
                st.push(nums2[i]);
            }
        }
    }
};

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    auto ans = Solution().nextGreaterElement(nums1, nums2);
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
