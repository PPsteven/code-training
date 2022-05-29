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
using namespace std;

// 第一个元素是高度值，第二个元素存位置
// 元素的位置存储取消方法: (x, y) => x * n + y
typedef pair<int, int> p;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int n = heightMap.size();
        const int m = heightMap[0].size();
        // 无法围成桶
        if (n <= 2 || m <= 2) {
            return 0;
        }

        vector<bool> visited(n*m, false);
        // first: type second: container third: order
        priority_queue<p, vector<p>, greater<p>> pq;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                // 边界
                if (i==0 || i==n-1 || j==0 || j==m-1) {
                    pq.push({heightMap[i][j], i*m+j});
                    visited[i*m+j] = true;
                }
            }
        }

        int ans=0;
        int dir[5] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            // 这是一圈木桶最短的部分
            auto cur = pq.top(); pq.pop();
            for (int i=0; i<4; i++) {
                int nx = cur.second / m + dir[i];
                int ny = cur.second % m + dir[i+1];
                if (nx >=0 && nx<n && ny>=0 && ny<m && !visited[nx*m+ny]) {
                    // 如果周围的格子比木桶最短的地方都矮，那么一定可以铸水
                    if (heightMap[nx][ny] < cur.first) {
                        ans += cur.first - heightMap[nx][ny];
                    }
                    visited[nx*m+ny] = true;
                    // 如果出现更高的木板，就添加入队。如果没有，就填入最高的水位
                    pq.push({max(heightMap[nx][ny], cur.first), nx*m+ny});
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    auto ans = Solution().trapRainWater(heightMap);
    cout << ans << endl;
    return 0;
}
