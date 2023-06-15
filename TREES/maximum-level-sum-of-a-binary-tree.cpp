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
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*>q;

        q.push(root);

        int lvl = 0,res = 0;
        int maxSum = INT_MIN;

        while(!q.empty())
        {
            lvl++;
            int sm = 0;

            for(int i=q.size();i>0;i--)
            {
                TreeNode* t = q.front();
                q.pop();
                sm += t->val;

                if(t->left != nullptr)
                {
                    q.push(t->left);
                }
                if(t->right != nullptr)
                {
                    q.push(t->right);
                }
            }

            if(maxSum < sm)
            {
                maxSum = sm;
                res = lvl;
            }
        }

        return res;

        
    }
};
