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
    
    int cnt = 0; // delared count for good node to 0
    
    // trav() is a recursive function which first
    
    void trav(TreeNode* root,int mx)
    {
        if(!root) return;
        
        if(root->val >= mx)
        {
            cnt++;
            mx = root->val;
        }
        
        trav(root->left,mx);
        trav(root->right,mx);
        
    }
    
    int goodNodes(TreeNode* root) {
        
        
        trav(root,root->val);
        
        return cnt;
        
    }
};


/*
Time Complexity: O(Nlog(n))
space Complexity: O(N)   as we have extra auxilary stack space 

*/
