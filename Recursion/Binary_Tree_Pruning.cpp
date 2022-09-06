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
    
    bool isOne(TreeNode* root)
    {
        if(!root) return false;
        
        
        bool leftSubtree = isOne(root->left);
        
        bool rightSubtree = isOne(root->right);
        
        if(!leftSubtree)
        {
            root->left = NULL;
            
        }
        
        if(!rightSubtree)
        {
            root->right = NULL;
            
        }
        
        return root->val == 1||leftSubtree||rightSubtree;
        
        
        
        
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!root) return root;
        
       if(isOne(root))
        {
            return root;
        }
        else{
            return NULL;
            
        }
        
        
        
        
    }
};
