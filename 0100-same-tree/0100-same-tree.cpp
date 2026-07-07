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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>q1,q2;
        if(!p && q)
        {
            return false;
        }
        if(!q && p)
        {
            return false;
        }
        if(!q && !p){
            return true;
        }
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty())
        {
            TreeNode* fr1 = q1.front();
            q1.pop();
            TreeNode* fr2 = q2.front();
            q2.pop();
            if((fr1->val != fr2->val) || (fr1->left && !fr2->left) || (fr1->right && !fr2->right) || (!fr1->left && fr2->left) || (!fr1->right && fr2->right))
            {
                return false;
            }
            if(fr1->left)
            {
                q1.push(fr1->left);
            }
            if(fr1->right)
            {
                q1.push(fr1->right);
            }
            if(fr2->left)
            {
                q2.push(fr2->left);
            }
            if(fr2->right)
            {
                q2.push(fr2->right);
            }
        }
        return q1.empty() && q2.empty();
    }
};