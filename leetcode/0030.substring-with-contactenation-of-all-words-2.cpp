#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int word_len = words[0].length();
        int n_word = words.size();
        unordered_map<string, int> target;
        vector<int> ans;
        for (auto w: words) {
            target[w]++;
        }
        for (int i=0; i<word_len; i++) {
            // 本解法和解法一区别就是起点不一致
            int l = i;
            int r = i;
            unordered_map<string, int> visited;
            while (r < n) {
                string cur_s = s.substr(r, word_len);
                if (target.find(cur_s) == target.end()) {
                    r += word_len;
                    l = r;
                    visited.clear();
                    continue;
                }
                if (visited[cur_s] < target[cur_s]) {
                    visited[cur_s]++;
                    r += word_len;
                    // find answer
                    if (r - l == n_word * word_len) {
                        ans.push_back(l);
                    }
                } else {
                    visited[s.substr(l, word_len)]--;
                    l += word_len;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words = {"a", "a"};
    vector<int> ans = Solution().findSubstring("aaa", words);
    for (int pos: ans) {
        printf("=> %d ", pos);
    }
    printf("\n");
    return 0;
}
