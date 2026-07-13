class Solution {
public:
    unordered_set<int> seen;

    bool dfs(TreeNode* root, int k) {
        if (!root) return false;

        if (seen.count(k - root->val))
            return true;

        seen.insert(root->val);

        return dfs(root->left, k) || dfs(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};