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
    int mod  = 1e9+7;
    long long totalSum  = 0;
    long long ans = 0;

    // dfsSum() is Seperate function for finding the seperate sum of whole tree//

    void dfsSum(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        totalSum += root->val;
        dfsSum(root->left);
        dfsSum(root->right);

    }

    int sumInternal(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }

        int leftSum = sumInternal(root->left);
        int rightSum = sumInternal(root->right);

       ans =  max({ans,(totalSum-leftSum)*leftSum,(totalSum-rightSum)*rightSum});    //Get the max product after making left or right subtrees as seprarate tree.
       return rightSum + leftSum + root->val;

    }






    int maxProduct(TreeNode* root) {

        if(!root)
        {
            return 0;
        }
        dfsSum(root);
        sumInternal(root);
        
        return ans%mod;

        
    }
};
