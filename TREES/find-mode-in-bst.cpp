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
    unordered_map<int,int>mp;
    
    void traverse(TreeNode *root)
    {
        if(!root)
        {
            return;
        }
        mp[root->val]++;
        traverse(root->left);
        
        traverse(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
        {
            return {root->val};
        }
        int maxF = 0;
        traverse(root);
        for(auto &[key,val]:mp)
        {
            maxF = max(maxF,val);
        }
        vector<int>res;
        
        for(auto& [key,val]:mp)
        {
            if(val == maxF)
            {
                res.push_back(key);
            }
        }
        return res;
        
    }
};
