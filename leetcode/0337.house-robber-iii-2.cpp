#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DP 0 not steal
//    1 have steal
// ans = max(cur_node[0], cur_node[1])
// cur_node[0] = cur_node->val + son_node[1]
// cur_node[1] = son_node[0]

struct dp {
    int steal;
    int not_steal;
};

class Solution {
public:
    int rob(TreeNode* root) {
        auto status = helper(root);
        return max(status.steal, status.not_steal);
    }

    dp helper(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto left = helper(root->left);
        auto right = helper(root->right);

        int steal = root->val + left.not_steal + right.not_steal;
        // 如果当前节点不偷，子节点可以偷，也可以不偷
        int not_steal = max(left.steal, left.not_steal) + max(right.steal, right.not_steal);
        return {steal, not_steal};
    }
};


