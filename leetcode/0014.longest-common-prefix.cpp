#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int max_len = 0;
        for (int i=0; i< strs.size(); i++) {
            if (strs[i].length() > max_len) {
                max_len = strs[i].length();
            }
        }
        for (int j=0; j<max_len; j++) {
            char c = strs[0][j];
            for (int i=1; i< strs.size(); i++) {
                if (strs[i][j] != c) {
                    return ans;
                }
            }
            ans = ans + c;
        }
        return ans;
    }
};
