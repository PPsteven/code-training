#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

// 普通模拟法
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool pos = true;
        // use type long to process INT_MAX & INT_MIN
        long ans = 0;
        // remove trailinng space
        while (i < s.length() && s[i] == ' ') i++;
        // + and - must followed by digit
        if (s[i]=='+' || s[i] == '-') {
            if (i+1 < s.length() && is_digit(s[i+1])) {
                if (s[i] == '-') {
                    pos = false;
                }
            } else {
                return 0;
            }
            i++;
        }
        while (i < s.length() && is_digit(s[i])) {
            ans = 10 * ans + (s[i] - '0');
            i++;
            if (ans > INT_MAX) {
                if (pos) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
        }

        if (!pos) {
            ans *= -1;
        }

        return ans;
    }

    bool is_digit(char c) {
        return ('0' <= c && c <= '9');
    }
};

int main() {
    int ans = Solution().myAtoi("21474836460");
    cout << ans << endl;
    return 0;
}
