#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

// point right move : when windows is not found, move to find the window.
// point left move :  when windows is found, move to shrink the window and found the minimum window.
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = -1;
        int n = s.length();
        int ans_len = INT_MAX;
        string ans;
        unordered_map<char, int> mp;
        for (auto c: t){
            mp[c]++;
        }
        unordered_map<char, int> visited;
        while (l < n) {
            bool find_answer = true;
            for (auto& it: mp) {
                if (visited[it.first] < mp[it.first]) {
                    find_answer = false;
                    break;
                }
            }

            if (find_answer) {
                if (r - l + 1 < ans_len) {
                    ans = s.substr(l, r - l + 1);
                    ans_len = r - l + 1;
                }
            }

            // a little tip: when r - l + 1 large than ans_len, point right move is meaningless.
            if (r+1<n && !find_answer && r - l + 1 < ans_len) {
                visited[s[++r]]++;
            } else {
                visited[s[l++]]--;
            }
        }
        return ans;
    }
};


int main() {
    string ans = Solution().minWindow("aNbdc", "ab");
    printf("%s\n", ans.c_str());
    return 0;
}
