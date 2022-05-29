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

class Solution {
public:
    // 单调栈 + 哨兵
    int largestRectangleArea(vector<int>& heights) {
        // 添加头尾哨兵, [0, ..., 0]
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        const int n = heights.size();
        stack<int> st; // 单调递增栈
        int ans = 0;
        int top;
        for (int i=0; i<n; i++) {
            // 碰到小的元素，左侧元素的高度没法构成正方形，故开始计算
            while (!st.empty() && heights[i] < heights[st.top()]) {
                top = st.top(); st.pop();
                // st.top() 是栈内剩下的元素，一定是比当前高度小的高度，一定也不能构成正方形
                ans = max(ans, heights[top] * (i - st.top() - 1));
            }
            st.push(i);
        }
        // 此时由于最后一个元素为0，所以一定能将栈中元素全部弹出
        return ans;
    }

    // 左右单调栈
    int largestRectangleArea2(vector<int>& heights) {
        const int n = heights.size();
        stack<int> st;
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        // from left to right to build stack(increasing)
        for (int i=0; i<n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
        // !!! an efficient way to clear stack
        st = stack<int>();
        // from right to left to build stack(increasing)
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            right[i] = st.empty() ? n-1: st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            // left[i] store the index of heights that less than current height
            // right[i] store the index of heights that less than current height
            // width = right[i] - left[i] - 1
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }

    // 单调栈+ 不使用哨兵情况
    int largestRectangleArea3(vector<int>& heights) {
        const int n = heights.size();
        stack<int> st; // 单调递增栈
        int ans = 0;
        int top;
        int left_idx;
        for (int i=0; i<n; i++) {
            if (st.empty()) {
                st.push(i);
                continue;
            }
            // 碰到小的元素，左侧元素的高度没法构成正方形，故开始计算
            while (!st.empty() && heights[i] < heights[st.top()]) {
                top = st.top(); st.pop();
                left_idx = st.empty() ? -1 : st.top();
                ans = max(ans, heights[top] * (i - left_idx - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            top = st.top(); st.pop();
            left_idx = st.empty() ? -1 : st.top();
            ans = max(ans, heights[top] * (n - left_idx - 1));
        }
        // 此时由于最后一个元素为0，所以一定能将栈中元素全部弹出
        return ans;
    }

};



int main() {
    // vector<int> heights = {2,1,5,6,2,3};
    vector<int> heights = {2,1,2};
    // auto ans = Solution().largestRectangleArea(heights);
    // cout << ans << endl;

    // ans = Solution().largestRectangleArea2(heights);
    // cout << ans << endl;

    auto ans = Solution().largestRectangleArea3(heights);
    cout << ans << endl;
    return 0;
}
