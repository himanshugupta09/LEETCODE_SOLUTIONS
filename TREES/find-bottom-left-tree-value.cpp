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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        TreeNode* cur = root;
        q.push(cur);
        
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            if(cur->right != nullptr)
            {
                q.push(cur->right);
            }
            if(cur->left != nullptr)
            {
                q.push(cur->left);
            }
                
        }
        return cur->val;
    }
};
