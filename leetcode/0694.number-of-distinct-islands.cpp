#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

// 本题的前提是旋转的不管，所以只需要对搜索的路径去重.
class Solution {
public:
    unordered_set<string> island;
    int n, m;

    int numDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    string path = dfs(grid, i, j, 'R');
                    island.insert(path);
                    cout << path << endl;
                }
            }
        }
        return island.size(); }

    string dfs(vector<vector<int>>& grid, int i, int j, char c) {
        if (i<0 || i>= n || j<0 || j>=m || grid[i][j] != 1) {
            return "";
        }
        // 设置为2 代表已经访问过了，节省了空间
        grid[i][j] = 2;
        string ans;
        ans = c;

        ans += dfs(grid, i+1, j, 'd');
        ans += dfs(grid, i-1, j, 'u');
        ans += dfs(grid, i, j+1, 'r');
        ans += dfs(grid, i, j-1, 'l');
        // 这一步非常重要，为每一层遍历提供了隔断，防止方向不清.
        ans += ";";
        return ans;
    }

};

int main() {
    vector<vector<int>> grid = {{1,1,0,1,1},{1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}};
    int ans = Solution().numDistinctIslands(grid);
    cout << ans << endl;
    return 0;
}
