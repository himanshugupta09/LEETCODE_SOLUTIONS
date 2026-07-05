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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 1;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while (!q.empty()) {
            int l = q.size();

            long long minL = q.front().second;   // normalize to avoid overflow
            long long first, last;

            for (int i = 0; i < l; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= minL;

                if (i == 0) first = idx;
                if (i == l - 1) last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx + 1});

                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }

            maxWidth = max(maxWidth, (int)(last - first + 1));
        }

        return maxWidth;
    }
};