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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*>stk;
        int index = 0;
        while(index  < traversal.size())
        {
            int dept = 0;
            while(index < traversal.size() && traversal[index] == '-')
            {
                dept++;
                index++;
            }
            int val = 0;
            while(index < traversal.size() && isdigit(traversal[index]))
            {
                val = val*10+(traversal[index]-'0');
                index++;
            }
            TreeNode* node = new TreeNode(val);
            while(stk.size() > dept)
            {
                stk.pop();
            }
            if(!stk.empty())
            {
                if(stk.top()->left == nullptr)
                {
                    stk.top()->left = node;
                }
                else
                {
                    stk.top()->right = node;
                }
            }
            stk.push(node);
        }
        while(stk.size() > 1)
        {
            stk.pop();
        }
        return stk.top();
    }
};