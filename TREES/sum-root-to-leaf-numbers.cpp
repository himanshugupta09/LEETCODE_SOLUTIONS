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
    
    int doTrav(TreeNode* root,int curSum)
    {
        if(root == NULL)
        {
            return 0;
        }
        curSum = curSum*10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            return curSum;
        }
        int Left = doTrav(root->left,curSum);
        int Right = doTrav(root->right,curSum);

        return Left+Right;

        
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return doTrav(root,sum);

        
    }
};
