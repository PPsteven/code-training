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

class Solution {
public:
    string decodeString(string s) {
        string tmp;
        stack<int> cout_st;
        stack<string> string_st;
        int cnt;
        string tmp_s;
        char c;
        char pre_c;
        for (int i=0; i<s.length(); i++) {
            c = s[i];
            if (i>0) {
                pre_c = s[i-1];
            }
            if (c == '[') {
                cout_st.push(stoi(tmp)); tmp.clear();
                string_st.push("[");
            } else if (c == ']') {
                string_st.push(tmp); tmp.clear();
                tmp_s.clear();
                while (string_st.top() != "[") {
                    tmp_s = string_st.top() + tmp_s; string_st.pop();
                }
                string_st.pop();
                cnt = cout_st.top(); cout_st.pop();
                string_st.push(dup_string(tmp_s, cnt));
            } else {
                // corner case: ab4
                // if cur char is digit and pre char is letter
                if (is_digit(c) && is_letter(pre_c)) {
                    string_st.push(tmp); tmp.clear();
                }
                tmp += c;
                // another way: push single letter into stack
                // stack of cba
                // a
                // b
                // c
            }
        }
        if (tmp.length()>0) {
            string_st.push(tmp);
        }
        string ans;
        while (!string_st.empty()) {
            ans = string_st.top() + ans;
            string_st.pop();
        }
        return ans; }

    string dup_string(string s, int cnt) {
        string ans;
        for (int i=0; i<cnt; i++) {
            ans += s;
        }
        return ans;
    }

    bool is_digit(char c) {
        return c >= '0' && c <= '9';
    }

    bool is_letter(char c) {
        return c >= 'a' && c <= 'z';
    }
};


int main() {
    string ans = Solution().decodeString("3[a2[bc]]ef");
    cout << ans << endl;
    return 0;
}
