#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        stack<int> st;
        int bottom = 0;
        int width = 0;
        int pool_h = 0;
        const int n = height.size();
        for (int i=0; i<n; i++) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                bottom = height[st.top()]; st.pop();
                if (!st.empty()) {
                    width = i-st.top()-1;
                    pool_h = min(height[i], height[st.top()]) - bottom;
                    ans += width * pool_h;
                }
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    // vector<int> height = {2,1,0,0,1};
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {4,2,0,3,2,5};
    int ans = Solution().trap(height);
    cout << ans << endl;
    return 0;
}
