// 暴力法，还有KMP 解法
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        bool is_equal;
        for (int i=0; i <= n - m; i++) {
            is_equal = true;
            for (int j=i; j<i+m;j++) {
                if (haystack[j] != needle[j-i]) {
                    is_equal = false;
                    break;
                }
            }
            if (is_equal) {
                return i;
            }
        }
        return -1;
    }
};


int main() {
    int ans = Solution().strStr("aab", "ab");
    cout << ans << endl;
    return 0;
}
