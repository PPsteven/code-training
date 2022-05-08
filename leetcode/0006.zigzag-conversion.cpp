#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;


// 其实无需矩阵，就是简单的直下直上法，只是需要用一个数组把
// 每一层的结果保存，最后统一输出。
class Solution {
public:
    string convert(string s, int numRows) {
        // numRows = 1 的这种特殊情况需要考虑到，属于Corner Case.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        string arr[numRows];
        for (int i=0; i<numRows; i++) {
            arr[i] = "";
        }
        int d = 1;
        int p = 0;
        for (int i=0; i<s.length(); i++) {
            arr[p].push_back(s[i]);
            if (p == numRows-1) {
                d = -1;
            } else if (p == 0) {
                d = 1;
            }
            p = p + d;
        }
        string ans ="";
        for (int i=0; i<numRows; i++) {
            ans += arr[i];
        }
        return ans;
    }
};

int main() {
    string ans = Solution().convert("PAYPALISHIRING", 3);
    printf("%s\n", ans.c_str());
    return 0;
}
