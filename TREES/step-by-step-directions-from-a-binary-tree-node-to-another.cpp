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
    TreeNode* LCA(TreeNode* node,int n1,int n2)
    {
        if(!node)
        {
            return NULL;
        }
        if(node->val == n1 || node->val == n2)
        {
            return node;
        }
        TreeNode* lefty = LCA(node->left,n1,n2);
        TreeNode* righty = LCA(node->right,n1,n2);
        
        if(!lefty){
            return righty;
        }
        else if(!righty)
        {
            return lefty;
        }
        else
        {
            return node;
        }
    }
    bool pathFinder(TreeNode* node,int tar,string& path)
    {
        if(!node)
        {
            return false;
        }
        if(node->val == tar)
        {
            return true;
        }
        path.push_back('L');
        
        if(pathFinder(node->left,tar,path))
        {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(pathFinder(node->right,tar,path))
        {
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root,startValue,destValue);
        string paths;
        string dest;
        
        pathFinder(lca,startValue,paths);
        pathFinder(lca,destValue,dest);
        
        string dirs;
        
        dirs.append(paths.length(),'U');
        dirs.append(dest);
        
        return dirs;
        
    }
};
