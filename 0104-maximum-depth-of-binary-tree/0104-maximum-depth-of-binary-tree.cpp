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
    int maxDepth(TreeNode* root) {
        int maxD = -1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        if(!root)
        {
            return 0;
        }
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto [node,h] = q.front();
                q.pop();
                maxD = max(maxD,h);
                if(node->left)
                {
                    q.push({node->left,h+1});
                }
                if(node->right)
                {
                    q.push({node->right,h+1});
                }
            }
        }
        return maxD;
    }
};