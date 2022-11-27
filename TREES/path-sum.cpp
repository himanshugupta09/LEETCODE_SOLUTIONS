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
    
    bool ok = false;
    
    void trav(TreeNode* root,int sum,int targetSum)
    {
        if(root == NULL)
        {
            return;
            
        }
        sum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum)
            {
                ok = true;
                
            }
            
            
        }
        
        trav(root->left,sum,targetSum);
        trav(root->right,sum,targetSum);
        
        
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        trav(root,0,targetSum);
        
        return ok;
        
    }
};
