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
    string tree2str(TreeNode* root) {
        
        if(root == NULL)
        {
            
            return "";
        }
     
        stack<TreeNode*>s;
        
        set<TreeNode*>visited;
        
        s.push(root);
        
        string res;
        
        
        
        while(!s.empty())
        {
            root = s.top();
            
            if(visited.find(root) != visited.end())
            {
                s.pop();
                res += ")";
                
            }
            else{
                
                visited.insert(root);
                res += "(" + to_string(root->val);
                
                if(root->left == NULL && root->right != NULL)
                {
                    res += "()";
                    
                }
                if(root->right != NULL)
                {
                    s.push(root->right);
                    
                }
                if(root->left != NULL)
                {
                    s.push(root->left);
                    
                }
                
            }
        }
        return res.substr(1,res.length()-2);
        
        
        
    }
};
