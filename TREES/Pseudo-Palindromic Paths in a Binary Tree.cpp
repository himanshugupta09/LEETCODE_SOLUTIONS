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
    
    int cnt = 0;
    
    void preorder(TreeNode* node,int path)
    {
        if(node != NULL)
        {
            path ^= (1 << node->val);
            
            if(node->left == NULL && node->right == NULL)
            {
                if((path &(path -1)) == 0)
                {
                    ++cnt;
                    
                }
            }
            preorder(node->left,path);
            preorder(node->right,path);
            
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root,cnt);
        return cnt;
        
    }
};

/*
Time complexity: O(N) since one has to visit each node, check if at most one digit has an odd frequency.

Space complexity: up to O(H) to keep the recursion stack, where HH is a tree height.
*/
