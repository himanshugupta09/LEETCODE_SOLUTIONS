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
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return 1;
        }
        if(root->left)
        {
            return 1+dfs(root->left);
        }
        if(root->right)
        {
            return 1+dfs(root->right);
        }
        return 0;
    }
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
       
        return max(maxDepth(root->left),maxDepth(root->right))+1;

    }
};