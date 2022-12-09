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

    int dfs(TreeNode* root,int curMax,int curMin)
    {
        if(root == NULL)
        {
            return curMax-curMin;
        }

        curMax = max(root->val,curMax);
        curMin = min(root->val,curMin);

        int left = dfs(root->left,curMax,curMin);
        int right = dfs(root->right,curMax,curMin);

        return max(left,right);

    }

    int maxAncestorDiff(TreeNode* root) {
        
        if(!root)
        {
            return 0;
        }
        return dfs(root,root->val,root->val);
    }
};
