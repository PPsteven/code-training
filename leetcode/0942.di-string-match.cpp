#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        int l = 0, r = n;
        vector<int> ans;
        for (auto c: s) {
            if (c == 'I') {
                ans.push_back(l++);
            } else {
                ans.push_back(r--);
            }
        }
        ans.push_back(r);
        return ans;
    }
};

int main() {
    auto ans = Solution().diStringMatch("IDID");
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
