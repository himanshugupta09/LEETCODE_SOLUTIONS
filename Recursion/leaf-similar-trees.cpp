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
    vector<int>tree_last1;
    vector<int>tree_last2;


    void dfs(TreeNode* root,vector<int> &s)
    {
        if(root->left == NULL && root->right == NULL)
        {
            s.push_back(root->val);
            return;
        }
        else if(root == NULL)
        {
            return;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            
            dfs(root->right,s);
        }
        else if(root->left != NULL && root->right == NULL)
        {
            
            dfs(root->left,s);
        }
        else
        {
            dfs(root->left,s);
            dfs(root->right,s);

        }

    }

    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        dfs(root1,tree_last1);
        dfs(root2,tree_last2);

        if(tree_last1.size() != tree_last2.size())
        {
            return false;
        }

        for(int i=0;i<tree_last1.size();i++)
        {
            if(tree_last1[i] != tree_last2[i])
            {
                return false;
            }
        }
        return true;







    }
};
