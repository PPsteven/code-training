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
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        const int n = heights.size();
        for (int i=0; i<volume; i++) {
            int cur = k;
            int pos = k;
            while (cur-1>=0 && heights[cur-1]<=heights[cur]) {
                if (heights[cur-1] < heights[cur]) {
                    pos = cur-1;
                }
                cur--;
            }
            // 没有移动
            if (pos != k) {
                heights[pos]++;
                continue;
            }
            cur = k;
            pos = k;
            while (cur+1<n && heights[cur+1]<=heights[cur]){
                if (heights[cur+1] < heights[cur]) {
                    pos = cur+1;
                }
                cur++;
            }
            if (pos != k){
                heights[pos]++;
                continue;
            }
            heights[k]++;
        }
        return heights;
    }
};


int main() {
    // vector<int> heights = {2,1,1,2,1,2,2};
    vector<int> heights = {2,0,1,2,1,2,2};
    auto ans = Solution().pourWater(heights, 4, 3);
    for (int x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
