/*                                              APPROACH 1 : USING DFS FRECURSION
==========================================================================================================================================================================
*/
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
     vector<int>s;

     void dfs(TreeNode* root)
     {
         if(root != NULL)
         {
             s.push_back(root->val);
             dfs(root->left);
             dfs(root->right);


         }
         else{
             return;
         }
     }



    int countNodes(TreeNode* root) {

        dfs(root);
        return s.size();

        




    }
};



/*
======================================================================================================================================================================
                                                                  APPROACH 2 : ITERATIVE DFS
======================================================================================================================================================================
*/

// No. of nodes in a full binary tree of height h is (2 ^ h - 1)

class Solution {
public:
    
    int countNodes(TreeNode* root) {
        
        // base case
        
        if(root == NULL)
            return 0;
        
        // find left height and right height for root
        
        int left_height = 0;
        
        int right_height = 0;
        
        TreeNode* left_pointer = root;
        
        TreeNode* right_pointer = root;
        
        // cal. left height
        
        while(left_pointer)
        {
            left_height++;
            
            left_pointer = left_pointer -> left;
        }
        
        // cal. right height
        
        while(right_pointer)
        {
            right_height++;
            
            right_pointer = right_pointer -> right;
        }
        
        // if left_height == right_height, then no. of nodes in subtree will be pow(2, h) - 1
        
        if(left_height == right_height)
            return pow(2, left_height) - 1;
        
        // if left_height != right_height then calculate no. of nodes for both the left subtree and right subtree
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
