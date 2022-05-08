#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans = {"M", "CM" ,"D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        string ans = "";
        while (num != 0) {
            if (num >= nums[i]) {
                for (int j=0; j < num/nums[i]; j++) {
                    ans.append(romans[i]);
                }
                num = num % nums[i];
            } else {
                i++;
            }
        }
        return ans;
    }
};


int main() {
    string ans = Solution().intToRoman(1994);
    cout << ans << endl;
    return 0;
}
