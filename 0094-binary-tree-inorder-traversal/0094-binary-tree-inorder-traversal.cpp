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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        if(!root->left && !root->right)
        {
            return {root->val};
        }
        stack<TreeNode*>stk;
        unordered_set<TreeNode*>seen;
        stk.push(root);
        vector<int>res;
        while(!stk.empty())
        {
            TreeNode* top = stk.top();
            if(top == nullptr)
            {
                stk.pop();
                continue;
            }
            if(seen.count(top))
            {
                stk.pop();
                res.push_back(top->val);
                if(top->right)
                {
                    stk.push(top->right);
                }
            }
            else
            {
                seen.insert(top);
                if(top->left)
                {
                    stk.push(top->left);
                }
            }
        }
        return res;
    }
};