#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

// dfs + cache
class Solution {
public:
    map<pair<int, int>, int> cache;
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, 0, target);
    }

    int dfs(vector<int>& nums, int start, int target) {
        // cache
        if (cache.find({start, target}) != cache.end()) {
            return cache[make_pair(start, target)];
        }
        if (start == nums.size()) {
            if (target == 0) {return 1;}
            else {return 0;}
        }
        int v = dfs(nums, start+1, target+nums[start]) + dfs(nums, start + 1, target-nums[start]);
        cache[{start, target}] = v;
        return v;
    }
};

int main() {
    vector<int> nums = {1, 1};
    auto ans = Solution().findTargetSumWays(nums, 0);
    cout << ans << endl;
    return 0;
}

// 0 -2
// 1 -1
// 2 0

