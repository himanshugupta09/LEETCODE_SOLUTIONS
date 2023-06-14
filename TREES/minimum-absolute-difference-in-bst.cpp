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

    vector<int>TreeNodes;

    void Traverser(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        Traverser(root->left);
        TreeNodes.push_back(root->val);
        Traverser(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        Traverser(root);
        sort(TreeNodes.begin(),TreeNodes.end());

        int mini = INT_MAX;

        for(int i=1;i<TreeNodes.size();i++)
        {
            mini = min(mini,(TreeNodes[i] - TreeNodes[i-1]));
        }

        return mini;


    }
};
