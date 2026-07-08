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
    int maxSum = INT_MIN;
    int getSum(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
       
        int leftSum = max(0, getSum(root->left));
        int rightSum = max(0, getSum(root->right));
        int curSum = root->val+leftSum+rightSum;
        maxSum = max(maxSum,curSum);
        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int sum = getSum(root);
        return maxSum;
    }
};