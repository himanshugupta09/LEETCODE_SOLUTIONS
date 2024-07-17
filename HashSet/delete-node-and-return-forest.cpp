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
    //unordered_map<int,TreeNode*>treeMap;
    TreeNode* traverse(TreeNode* root,unordered_set<int>&tbd,vector<TreeNode*>&res)
    {
        if(!root)
        {
            return nullptr;
        }
        root->left = traverse(root->left,tbd,res);
        root->right = traverse(root->right,tbd,res);
        
        if(tbd.find(root->val) != tbd.end())
        {
            if(root->left)
            {
                res.push_back(root->left);
            }
            if(root->right)
            {
                res.push_back(root->right);
            }
            delete root;
            return nullptr;
        }
        return root;
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int>tbd(to_delete.begin(),to_delete.end());
        vector<TreeNode*>res;
        
        root = traverse(root,tbd,res);
        if(root)
        {
            res.push_back(root);
        }
        return res;
        
        
    }
};
