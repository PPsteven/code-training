#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int reversed_number = 0;
        // corner case: 0, 100
        // if last number of x is 0, only number zero is Palindrome
        if (x < 0 || x % 10 ==0) {
            return false;
        }
        // 必须折半比较，因为翻转后可能超过int限制
        while (reversed_number < x) {
            reversed_number = x % 10 + reversed_number * 10;
            x = x / 10;
        }
        // case: 121 and 11
        return reversed_number == x || reversed_number /10  == x;
    }
};


int main() {
    bool ans;
    ans = Solution().isPalindrome(101);
    cout << ans << endl;
    return 0;
}
