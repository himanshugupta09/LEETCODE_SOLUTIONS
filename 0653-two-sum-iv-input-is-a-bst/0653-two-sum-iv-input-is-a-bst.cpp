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
    bool hasSum = false;

    set<int>nums;

    void helper(TreeNode* root,int k)
    {
        if(!root)
        {
            return;
        }
        if(nums.find(k-root->val) != nums.end())
        {
            hasSum = true;
            return;
        }
        else
        {
            nums.insert(root->val);
            helper(root->left,k);
            helper(root->right,k);
        }
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        helper(root,k);
        return hasSum;
    }
};