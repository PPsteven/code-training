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
    vector<vector<int>> findLeaves(TreeNode* root) {
        get_level(root);
        return ans;
    }

    vector<vector<int>> ans;
    int get_level(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int cur_level = 1 + max(get_level(root->left), get_level(root->right));

        // 保证不越界
        if (cur_level-1==ans.size()) {
            ans.push_back({});
        }
        ans[cur_level-1].push_back(root->val);
        return cur_level;
    }
};
