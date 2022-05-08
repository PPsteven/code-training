#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Automation {
    string state = "start";
    unordered_map<string, vector<string>> mp = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    string transit(string state, char c) {
        if (c == ' ') return mp[state][0];
        if (c == '+' || c == '-') return mp[state][1];
        if ('0' <= c && c <= '9') return mp[state][2];
        return mp[state][3];
    };

    // Be Catious: -INT_MAX != INT_MIN
    public:
    int sign = 1;
    long ans = 0;
    void read(char c) {
        state = transit(state, c);
        if (state == "signed" && c == '-')
            sign = -1;
        if (state == "in_number") {
            ans = 10 * ans + c - '0';
            if (ans > INT_MAX) {
                state = "end";
            }
        }
    }
    int result() {
        ans = ans * sign;
        if (ans > INT_MAX) {
            return INT_MAX;
        } else if (ans < INT_MIN) {
            return INT_MIN;
        }
        return ans;
    }
};

// string
class Solution {
public:
    int myAtoi(string s) {
        Automation m;
        for (char c: s) {
            m.read(c);
        }
        return m.result();
    }
};

int main() {
    int ans = Solution().myAtoi("-91283472332");
    cout << ans << endl;
    return 0;
}
