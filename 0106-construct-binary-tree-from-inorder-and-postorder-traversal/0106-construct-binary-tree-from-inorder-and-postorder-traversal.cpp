class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& inorder, int inL, int inR,
                    vector<int>& postorder, int postL, int postR) {

        if (postL > postR)
            return nullptr;

        int rootVal = postorder[postR];
        TreeNode* root = new TreeNode(rootVal);

        int k = pos[rootVal];
        int leftSize = k - inL;

        root->left = build(inorder,
                           inL,
                           k - 1,
                           postorder,
                           postL,
                           postL + leftSize - 1);

        root->right = build(inorder,
                            k + 1,
                            inR,
                            postorder,
                            postL + leftSize,
                            postR - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        return build(inorder,
                     0,
                     inorder.size() - 1,
                     postorder,
                     0,
                     postorder.size() - 1);
    }
};