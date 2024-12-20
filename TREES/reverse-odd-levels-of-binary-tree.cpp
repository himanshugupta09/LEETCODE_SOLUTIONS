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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int lvl = 0;
        vector<TreeNode*>a;
        while(!q.empty())
        {
            int n = q.size();
            TreeNode* f = q.front();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* f = q.front();
                q.pop();
                if(lvl%2)
                {
                    a.push_back(f);
                }
                if(f->left)
                {
                    q.push(f->left);
                }
                if(f->right)
                {
                    q.push(f->right);
                }
            }
            if(lvl%2)
            {
                for(int i=0;i<a.size()/2;i++)
                {
                    swap(a[i]->val, a[a.size()-i-1]->val);
                }
            }
            a.clear();
            lvl++;
            
        }
        return root;
    }
};
