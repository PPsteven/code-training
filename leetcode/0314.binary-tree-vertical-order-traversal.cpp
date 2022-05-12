// Definition for a binary tree node.
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        get_level(root, -1);
        return ans;
    }

    vector<vector<int>> ans;
    int get_level(TreeNode* root, int level) {
        if (!root) {
            return -1;
        }
        int cur_level = max(level, 1 + get_level(root->left, level - 1));

        // 保证不越界
        if (cur_level==ans.size()) {
            ans.push_back({});
        }
        ans[cur_level].insert(ans[cur_level].begin(), root->val);

        get_level(root->right, cur_level + 1);

        return cur_level;
    }
};
