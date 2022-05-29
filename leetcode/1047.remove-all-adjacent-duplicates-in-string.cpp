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

// tips  use string instead of stack
class Solution {
public:
    string removeDuplicates(string s) {
        string tmp_s;
        for (char c: s) {
            if (!tmp_s.empty() && c == tmp_s.back()) {
                tmp_s.pop_back();
            } else {
                tmp_s.push_back(c);
            }
        }
        return tmp_s;
    }
};

int main() {
    string ans = Solution().removeDuplicates("abbaca");
    cout << ans << endl;
    return 0;
}
