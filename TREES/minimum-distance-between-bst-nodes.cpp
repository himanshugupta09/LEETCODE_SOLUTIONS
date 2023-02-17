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
    vector<int>nums;

    void trav(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        trav(root->left);
        nums.push_back(root->val);
        
        trav(root->right);
    }
    int minDiffInBST(TreeNode* root) {

        if(!root)
        {
            return 0;
        }
        int minn = INT_MAX;
        trav(root);

        for(int i=1;i<nums.size();i++)
        {
            minn = min(minn,(nums[i] - nums[i-1]));
        }

        return minn;
        
    }
};
