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

// BST 树的特点
// 用一个值记录之前弹出所有数字的最大值，后续加入的数值一定是小于
// 之前弹出的最大值，否则就报错。
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int max_pop_number = INT_MIN;
        for (int i=0; i<preorder.size(); i++) {
            if (preorder[i] < max_pop_number) {
                return false;
            }
            while (!st.empty() && preorder[i] > st.top()) {
                max_pop_number = max(max_pop_number, st.top());
                st.pop();
            }
            st.push(preorder[i]);
        }
        return true;
    }
};

int main() {
    vector<int> preorder = {5,2,1,3,6};
    auto ans = Solution().verifyPreorder(preorder);
    cout << ans << endl;
    return 0;
}
