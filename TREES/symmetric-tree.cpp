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
    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        

        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty())
        {
            TreeNode* Left = q.front();
            q.pop();
            TreeNode* Right = q.front();
            q.pop();

            if(Left == NULL && Right == NULL)
            {
               continue;
            }

            if(Left == NULL || Right == NULL  || Left->val != Right->val)
            {
                return false;
            }
            q.push(Left->left);
            q.push(Right->right);
            q.push(Left->right);
            q.push(Right->left);

        }
        return true;
    }
};
