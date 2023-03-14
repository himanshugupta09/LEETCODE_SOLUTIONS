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
vector<int>vals;
    void inOrderTrav(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        inOrderTrav(root->left);
        vals.push_back(root->val);
        inOrderTrav(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        inOrderTrav(root);

        int res;
        int i = 0;
        while(i != k)
        {
            res = vals[i];
            i++;
        }
        return res;




    }
};
