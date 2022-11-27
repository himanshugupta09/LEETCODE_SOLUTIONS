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
    
    void trav(TreeNode* root,int val,int depth,int lvl)
    {
        if(!root)
        {
            return;
        }
        if(lvl == depth-1)
        {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = l;
            root->right->right = r;
            return;
            
        }
        else{
            
            trav(root->left,val,depth,lvl+1);
            trav(root->right,val,depth,lvl+1);
            
        }
        
        
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        TreeNode* node;
        if(depth == 1){
            node = new TreeNode(val);
            node->left = root;
        }
        else{
            trav(root,val,depth,1);
        }

        
        
        
         return depth == 1 ? node : root;
        
        
    }
};
