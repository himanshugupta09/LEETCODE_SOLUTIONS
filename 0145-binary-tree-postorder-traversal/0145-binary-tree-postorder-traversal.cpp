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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>>stk;
        vector<int>res;
        stk.push({root,0});

        while(!stk.empty())
        {
            auto [node,vis] = stk.top();
            stk.pop();
            if(!node)
            {
                continue;
            }
            if(vis)
            {
                res.push_back(node->val);
            }
            else
            {
                stk.push({node,1});
                if(node->right)
                {
                    stk.push({node->right,0});
                }
                if(node->left)
                {
                    stk.push({node->left,0});
                }
            }
        }

        return res;

    }
};