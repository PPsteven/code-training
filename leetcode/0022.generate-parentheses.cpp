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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", n, n);
        return ans;
    }

    void helper(vector<string>& ans, string cur_s, int l, int r) {
        if (l > r || l < 0 || r <0 ) {
            return;
        }
        if (l==0 && r==0) {
            ans.push_back(cur_s);
        }
        helper(ans, cur_s+'(', l-1, r);
        helper(ans, cur_s+')', l, r-1);
    }
};

int main() {
    auto ans = Solution().generateParenthesis(1);
    for (string x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
