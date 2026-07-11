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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n <= 1)
        {
            return new TreeNode(preorder[0]);
        }
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<n;i++)
        {
            TreeNode* curr = root;
            while(curr)
            {
                    if(curr->val < preorder[i] && !curr->right)
                    {
                        curr->right = new TreeNode(preorder[i]);
                        break;
                    }
                    else if(curr->val < preorder[i] && curr->right != NULL)
                    {
                        curr = curr->right;
                    }
                    else if(curr->val > preorder[i] && !curr->left)
                    {
                        curr->left = new TreeNode(preorder[i]);
                        break;
                    }
                    else if(curr->val > preorder[i] && curr->left != NULL)
                    {
                        curr = curr->left;
                    }
            }
                
            
        }
        return root;
    }
};