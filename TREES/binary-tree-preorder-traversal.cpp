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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>nodeStack;
        nodeStack.push(root);

        vector<int>res;

        if(root == NULL)
        {
            return res;
        }

        while(!nodeStack.empty())
        {
            TreeNode* Node = nodeStack.top();
            res.push_back(Node->val);

            nodeStack.pop();

            if(Node->right)
            {
                nodeStack.push(Node->right);

            }
            if(Node->left)
            {
                nodeStack.push(Node->left);
            }

        }

        return res;


    }
};
