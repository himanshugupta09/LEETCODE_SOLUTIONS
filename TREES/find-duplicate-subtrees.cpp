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
    vector<TreeNode*>res;
    unordered_map<string,int>mp;

    string trav(TreeNode* root)
    {
        if(!root)
        {
            return "";
        }
    string subpath = "(" + trav(root->left) + ")" + to_string(root->val) + "(" + trav(root->right) + ")";
        if(mp.find(subpath) == mp.end())
        {
            mp[subpath] = 1;
        }
        else
        {
            mp[subpath]++;
        }
        if(mp[subpath] == 2)
        {
            res.push_back(root);
        }

        return subpath;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        trav(root);

        return res;

    }
};
