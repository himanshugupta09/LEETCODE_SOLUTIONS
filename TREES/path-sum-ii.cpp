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
    
    vector<vector<int>>fin;
    vector<int>temp;
    
    void trav(TreeNode* root,vector<int> &temp,int sm,int targetSum)
    {
        if(!root)
        {
            return;
            
        }
        sm += root->val;
        temp.push_back(root->val);
        
        if(sm == targetSum && !root->left && !root->right)
        {
            fin.push_back(temp);
            
            
        }
        
        trav(root->left,temp,sm,targetSum);
        trav(root->right,temp,sm,targetSum);
        
        temp.pop_back();
        
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        trav(root,temp,0,targetSum);
            
        
        return fin;
        
        
    }
};
