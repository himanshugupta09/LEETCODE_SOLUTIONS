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
    int idx = 0;
    TreeNode* build(vector<int>&pre,int low,int high)
    {
        if(idx == pre.size())
        {
            return nullptr;
        }
        if(pre[idx] < low || pre[idx] > high)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[idx++]);
        root->left = build(pre,low,root->val);
        root->right = build(pre,root->val,high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,INT_MIN,INT_MAX);
    }
};