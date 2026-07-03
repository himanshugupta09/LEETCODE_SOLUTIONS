class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        TreeNode* lastVis = nullptr;

        while (curr || !stk.empty()) {

            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }

            TreeNode* top = stk.top();

            if (top->right && lastVis != top->right) {
                curr = top->right;
            }
            else {
                res.push_back(top->val);
                lastVis = top;
                stk.pop();
            }
        }

        return res;
    }
};