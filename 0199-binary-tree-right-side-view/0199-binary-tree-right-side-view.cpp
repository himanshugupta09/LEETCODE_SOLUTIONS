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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>res;
        if(!root)
        {
            return {};
        }
        q.push(root);
        while(!q.empty())
        {
           int l = q.size();
           bool first = false;
           for(int i=0;i<l;i++)
           {
               TreeNode* fr = q.front();
               q.pop();
               if(!first)
               {
                   res.push_back(fr->val);
                   first = true;
               }
               if(fr->right)
               {
                   q.push(fr->right);
               }
               if(fr->left)
               {
                   q.push(fr->left);
               }
           }
        }
        return res;
    }
};