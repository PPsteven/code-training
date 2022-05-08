// 多起点滑动窗口
// reference: https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/duo-qi-dian-hua-dong-chuang-kou-by-yexis-bl51/
// 滑动窗口的前提就是每个word 长度是一致的
// s, word_len
// 第1 次滑动检查点位 f(0), f(0+d), f(0+2d) ...
// 第2 次滑动检查f(1), f(1+d), f(1+2d) ...
// 第3 次滑动检查f(2), f(2+d), f(2+2d) ...
// ...
// 第word_len 次滑动f(2), f(2+d), f(2+2d) ...
// xxx|xxx|000|xxx 遇到非word就清空字典
// xxx|xxx|xxx|000

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
        int nword = words.size();
        if (nword < 0) {
            return {};
        }
        int slen = s.length();
        int wlen = words[0].length();
        unordered_map<string, int> target; for (auto w: words) {
            target[w]++;
        }
        vector<int> ans;

        // multi entry
        for (int i=0; i< wlen; i++) {
            int left = i;
            int right = i - wlen;
            unordered_map<string, int> visited;
            for (auto w: words) {
                visited[w] = 0;
            }
            while (right < slen) {
                if (right + wlen >= slen) {
                    break;
                }
                string cur_s = s.substr(right + wlen, wlen);
                if (target.find(cur_s) == target.end()) {
                    right += wlen;
                    left = right+wlen;
                    visited.clear();
                    continue;
                }
                if (visited[cur_s] < target[cur_s]) {
                    visited[cur_s]++;
                    right += wlen;
                    if (right - left + wlen == nword * wlen) {
                        ans.push_back(left);
                    }
                } else {
                    visited[s.substr(left, wlen)]--;
                    left += wlen;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words = {"foo", "bar"};
    vector<int> ans = Solution().findSubstring("barfoothefoobarman", words);
    for (int pos: ans) {
        printf("=> %d ", pos);
    }
    printf("\n");
    return 0;
}
