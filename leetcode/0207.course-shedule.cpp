#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> tables(numCourses);
        int cur, pre;
        for (int i=0; i<prerequisites.size(); i++) {
            cur = prerequisites[i][0];
            pre = prerequisites[i][1];
            tables[pre].push_back(cur);
            indegrees[cur]++;
        }
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        while (q.size() > 0) {
            cur = q.front();
            q.pop();
            for (int i=0; i<tables[cur].size(); i++) {
                indegrees[tables[cur][i]]--;
                if (indegrees[tables[cur][i]] == 0) {
                    q.push(tables[cur][i]);
                }
            }
            numCourses--;
        }
        return numCourses == 0;
    }
};

int main() {
    vector<vector<int>> prerequisites = {{0, 1}, {1, 0}};
    // vector<vector<int>> prerequisites = {{0, 1}};
    bool ans = Solution().canFinish(2, prerequisites);
    cout << ans << endl;
    return 0;
}
