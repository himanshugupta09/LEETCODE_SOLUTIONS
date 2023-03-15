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

    void getPaths(vector<string>& res,TreeNode* root,string s)
    {
        if(!root->left && !root->right)
        {
            res.push_back(s);
            return;
        }
        if(root->left)
        {
            getPaths(res,root->left,s + "->" + to_string(root->left->val));

        }
        if(root->right)
        {
            getPaths(res,root->right,s + "->" + to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(!root)
        {
            return res;
        }
        getPaths(res,root,to_string(root->val));
        return res;
    }
};
