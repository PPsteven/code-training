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
    int maximalSquare(vector<vector<char>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        int max_width = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    max_width = 1;
                }
            }
        }

        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    max_width = max(max_width, dp[i][j]);
                }
            }
        }
        return max_width * max_width;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1','0','1','1','1'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    auto ans = Solution().maximalSquare(matrix);
    cout << ans << endl;
    return 0;
}
