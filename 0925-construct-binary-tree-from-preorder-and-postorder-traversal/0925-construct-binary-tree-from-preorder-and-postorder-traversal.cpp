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
    unordered_map<int, int> postOrderIndexMap;    // Map to store the index of each value in postorder.

    // Function that constructs the binary tree from preorder and postorder traversal vectors.
    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
        // Fill the map with the postorder values and their indices.
        for (int i = 0; i < postorder.size(); ++i) {
            postOrderIndexMap[postorder[i]] = i;
        }
        // Call the recursive build function to construct the tree.
        return buildTree(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    // Helper function to recursively build the binary tree from preorder and postorder traversal subsets.
    TreeNode* buildTree(std::vector<int>& preorder, int preStart, int preEnd,
                        std::vector<int>& postorder, int postStart, int postEnd) {
        // If there are no elements to construct the tree, return nullptr.
        if (preStart > preEnd) return nullptr;

        // The first value in preorder is the root node value.
        TreeNode* root = new TreeNode(preorder[preStart]);

        // If there is only one node, it is the root of the current subtree.
        if (preStart == preEnd) return root;

        // Find the index of the root of the left subtree in postorder traversal using the map.
        int leftRootIndex = postOrderIndexMap[preorder[preStart + 1]];
      
        // The length of the left subtree in the postorder array can be calculated from the indices.
        int leftSubtreeLength = leftRootIndex - postStart + 1;

        // Recursively construct the left subtree.
        root->left = buildTree(preorder, preStart + 1, preStart + leftSubtreeLength,
                               postorder, postStart, leftRootIndex);

        // Recursively construct the right subtree.
        root->right = buildTree(preorder, preStart + leftSubtreeLength + 1, preEnd,
                                postorder, leftRootIndex + 1, postEnd - 1);

        // Return the root of the constructed subtree.
        return root;
    }
};