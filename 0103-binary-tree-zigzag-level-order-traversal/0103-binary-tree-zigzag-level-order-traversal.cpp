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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>res;
        if(!root)
        {
            return {};
        }
        q.push(root);
        int i = 0;
        while(!q.empty())
        {
            int ln = q.size();
            vector<int>t;
            for(int l=0;l<ln;l++)
            {
                TreeNode* fr = q.front();
                q.pop();
                t.push_back(fr->val);
                if(fr->left)
                {
                    q.push(fr->left);
                }
                if(fr->right)
                {
                    q.push(fr->right);
                }
            }
            if(i%2)
            {
                reverse(t.begin(),t.end());
                res.push_back(t);
                i++;
            }
            else
            {
                res.push_back(t);
                i++;
            }
        }
        return res;
    }
};