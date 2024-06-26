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
    vector<int> TreeNodes;

    void inorderTraversal(TreeNode* root) {
        if (!root) {
            return;
        }
        inorderTraversal(root->left);
        TreeNodes.push_back(root->val);
        inorderTraversal(root->right);
    }

    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(TreeNodes[mid]);
        node->left = sortedArrayToBST(start, mid - 1);
        node->right = sortedArrayToBST(mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        // Step 1: Perform inorder traversal to get the elements in sorted order
        inorderTraversal(root);

        // Step 2: Build a balanced BST from the sorted array
        return sortedArrayToBST(0, TreeNodes.size() - 1);
    }
   
};
