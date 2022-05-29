#include <cstring>
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        vector<int> heights(m+2, 0);
        int ans=0;
        for (int row=0; row<n; row++) {
            for (int col=0; col<m; col++) {
                if (matrix[row][col] == '1') {
                    heights[col+1] += 1;
                } else {
                    heights[col+1] = 0;
                }
            }
            //调用上一题的解法，更新函数
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

    // 单调栈 + 哨兵
    int largestRectangleArea(vector<int>& heights) {
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
};

int main() {
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int ans = Solution().maximalRectangle(matrix);
    cout << ans << endl;
    return 0;
}
