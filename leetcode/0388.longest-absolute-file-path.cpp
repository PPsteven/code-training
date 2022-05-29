#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        input += '\n';
        const int n = input.length();
        int ans = 0;
        int w = 0; // 文件目录或文件名长度
        int level=0; // 文件层级
        bool is_file = false; // 是否为文件
        stack<int> st; // 每一层存储绝对路径长度，/ 长度也算
        st.push(0); // 根目录（level=0）对应st大小为1
        for (int i=0; i<n; i++) {
            if (input[i] == '\n') {
                while (st.size() > level+1) {
                    st.pop();
                }
                // 根目录不带/, 子目录和文件名带/
                st.push(w+st.top()+ (level > 0 ? 1: 0)); w=0;
                cout << st.top() << endl;
                level = 0; // 文件层级
                if (is_file) { // 是文件
                    ans = max(ans, st.top());
                    is_file = false;
                }
            } else if (input[i] == '\t') {
                level++;
            } else {
                w++;
                if (input[i] == '.') {
                    is_file = true;
                }
            }
        }
        return ans;
    }
};
int main() {
    auto ans = Solution().lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
    cout << ans << endl;
    return 0;
}
