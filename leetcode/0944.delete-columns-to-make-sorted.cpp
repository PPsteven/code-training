#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        const int n = strs.size();
        const int m = strs[0].size();
        for (int col=0; col<m; col++) {
            for (int row=1; row<n; row++) {
                if (strs[row][col] < strs[row-1][col]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> strs = {"cba","daf","ghi"};
    auto ans = Solution().minDeletionSize(strs);
    cout << ans << endl;
    return 0;
}
