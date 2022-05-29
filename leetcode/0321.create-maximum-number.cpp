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
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();
        const int m = nums2.size();

        vector<int> ans;
        for (int d=max(0, k-m); d<=min(k, n); d++) {
            cout << d << endl;
            auto s1 = maxSubSequence(nums1, d);
            auto s2 = maxSubSequence(nums2, k-d);
            auto m = merge(s1, s2);
            if (greater(m, ans)) {
                ans = m;
            }
        }
        return ans;
    }

    bool greater(vector<int>& a, vector<int>&b) {
        if (b.size()==0){
            return true;
        }
        for (int i=0; i<a.size(); i++) {
            if (a[i] == b[i]) {
                continue;
            }

            return a[i] > b[i];
        }
        return false;
    }

    vector<int> maxSubSequence(vector<int>& nums, int k) {
        const int n = nums.size();
        stack<int> st;
        for (int i=0; i<n; i++) {
            while (n-i > k && !st.empty() && nums[i] > st.top()) {
                st.pop();
                k++;
            }
            if (k > 0) {
                st.push(nums[i]);
                k--;
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.insert(ans.begin(), st.top()); st.pop();
        }
        return ans;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        while (a.size()>0 || b.size()>0) {
            if (a.size()==0) {
                for (int j=0; j<b.size(); j++) {
                    ans.push_back(b[j]);
                }
                break;
            }

            if (b.size()==0) {
                for (int j=0; j<a.size(); j++) {
                    ans.push_back(a[j]);
                }
                break;
            }

            if (a[0] == b[0]) {
                if (greater(a, b)) {
                    ans.push_back(a[0]);
                    ans.erase(a.begin());
                } else {
                    ans.push_back(b[0]);
                    ans.erase(b.begin());
                }
            } else if (a[0] > b[0]){
                ans.push_back(a[0]);
                ans.erase(a.begin());
            } else {
                ans.push_back(b[0]);
                ans.erase(b.begin());
            }
        }
        return ans;
    }
};

// k = 5
// 5 from nums1 + 0 from nums2;
// 4 from nums1 + 1 from nums2
// 3 fron nums1 + 2 from nums2;
// ...

// 本题其实不难，主要是繁琐，分别从数组找到d, k-d 个最大元素
// 合并后取最大
int main() {
    vector<int> nums1 = {3,4,6,5};
    vector<int> nums2 = {9,1,2,5,8,3};
    auto ans = Solution().maxNumber(nums1, nums2, 4);
    for (int x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
