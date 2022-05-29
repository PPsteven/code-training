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
    bool isValid(string s) {
        vector<char> st;
        for (const char c:s) {
            switch (c) {
                case 'a':
                    st.push_back(c);
                    break;
                case 'b':
                    if (st.size()>0 && st[st.size()-1] =='a') {
                        st.push_back(c);
                    } else {
                        return false;
                    }
                    break;
                case 'c':
                    if (st.size()>1 && st[st.size()-1] == 'b'){
                        st.pop_back(); st.pop_back();
                    } else {
                        return false;
                    }
                    break;
            }
        }
        return st.size() == 0;
    }
};

int main() {
    bool ans = Solution().isValid("abcabc");
    cout << ans << endl;
    return 0;
}
