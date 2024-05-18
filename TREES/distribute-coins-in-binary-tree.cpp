/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int moves;
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        
        int lc = dfs(root->left);
        int rc = dfs(root->right);
        moves += abs(lc) + abs(rc);
        return (root->val - 1) + lc + rc;
    }
    int distributeCoins(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        dfs(root);
        return moves;
        
        
    }
};
