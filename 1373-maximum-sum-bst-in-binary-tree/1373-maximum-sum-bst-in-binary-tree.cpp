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
struct Info {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};
class Solution {
public:
    int maxSum=0;
    Info solve(TreeNode* root)
    {
        if(!root)
        {
            return  {true, INT_MAX, INT_MIN, 0};
        }

        struct Info left = solve(root->left);
        struct Info right = solve(root->right);
        if(left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal)
        {
            int sum = left.sum + root->val + right.sum;
            maxSum = max(maxSum,sum);
            return {
                    true,
                    min(left.minVal, root->val),
                    max(right.maxVal, root->val),
                    sum
                };
        }
        else
        {
            return {false, 0, 0, 0};
        }

    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};