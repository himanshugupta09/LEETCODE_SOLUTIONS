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
    unordered_map<int,int>pos;

    TreeNode* build(vector<int>&preorder,int preL, int  preR,vector<int>&inorder, int inL, int inR){
        if(preL > preR)
        {
            return nullptr;
        }
        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);
        int k = pos[rootVal];
        int leftSize = k-inL;
        root->left = build(preorder,preL+1,preL+leftSize,inorder,inL,k-1);
        root->right = build(preorder,
                            preL + leftSize + 1,
                            preR,
                            inorder,
                            k + 1,
                            inR);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            pos[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
};