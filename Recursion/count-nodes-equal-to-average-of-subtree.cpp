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
    int res = 0;
    pair<int,int>postOrder(TreeNode* root)
    {
        if(!root)
        {
            return {0,0};
        }
        pair<int,int> left = postOrder(root->left);
        pair<int,int> right = postOrder(root->right);
        
        int nodeSum  = left.first + right.first + root->val;
        int nodeCount = left.second + right.second + 1;
        
        if(root->val == nodeSum/(nodeCount))
        {
            res++;
        }
        
        return {nodeSum,nodeCount};
    }    
    int averageOfSubtree(TreeNode* root) {
        
        //int res = 0;
        postOrder(root);
        return res;
        
        
    }
};
