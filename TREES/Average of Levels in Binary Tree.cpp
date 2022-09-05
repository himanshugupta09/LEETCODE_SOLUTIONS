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
    vector<double> averageOfLevels(TreeNode* root) {
    
        
        vector<double>res;
        
        queue<TreeNode*>Q;
        
        Q.push(root);
        while(!Q.empty())
        {
            int n = Q.size();
            
            double sm = 0.0;
            
            for(int j = 0;j<n;j++)
            {
                TreeNode* f = Q.front();
                Q.pop();
                
                sm += f->val;
                
                if(f->left) Q.push(f->left);
                if(f->right) Q.push(f->right);
                
                
                
            }
            res.push_back(sm/n);
            
        }
        
        return res;
        
        
    }
};
