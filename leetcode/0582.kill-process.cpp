#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// hash + BFS
// hash + DFS 也是可行的
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> mp;
        queue<int> q;
        int cur;
        vector<int> ans;
        for (int i=0; i<ppid.size(); i++) {
            mp[ppid[i]].push_back(pid[i]);
        }

        ans.push_back(kill);
        q.push(kill);
        while (!q.empty()) {
            cur = q.front(); q.pop();
            if (mp.find(cur) != mp.end()) {
                auto subprocess = mp[cur];
                for (int i=0; i<subprocess.size(); i++) {
                    ans.push_back(subprocess[i]);
                    q.push(subprocess[i]);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> pid = {1, 3, 10, 5};
    vector<int> ppid = {3, 0 ,5, 3};
    auto ans = Solution().killProcess(pid, ppid, 3);
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
