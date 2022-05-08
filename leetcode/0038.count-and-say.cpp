#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        string after = "";
        for (int i=1; i<n; i++) {
            int l = 0;
            int r = 0;
            while (r < pre.length()) {
                while (r < pre.length() && pre[l] == pre[r]) {
                    r++;
                }
                after += to_string(r-l) + pre[l];
                l = r;
                }
            pre = after;
            after = "";
        }
        return pre;
    }
};

int main() {
    string ans = Solution().countAndSay(4);
    cout << ans << endl;
    return 0;
}
