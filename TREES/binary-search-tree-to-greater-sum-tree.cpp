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
    void getSum(TreeNode* root,int& sum)
    {
        if(!root)
        {
            return;
        }
        //root->val  = sum += root->val;
        getSum(root->right,sum);
        root->val  = sum += root->val;
        getSum(root->left,sum);

    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
        {
            return root;
        }
        int sum = 0;
        getSum(root,sum);
        return root;

        
    }
};
