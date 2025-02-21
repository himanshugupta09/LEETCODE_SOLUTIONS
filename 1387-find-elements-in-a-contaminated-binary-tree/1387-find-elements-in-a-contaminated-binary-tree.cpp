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
class FindElements {
public:
    set<int>hasValue;
    int lvl  = 0;
    void dfs(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        if(lvl ==  0) root->val = 0;
        hasValue.insert(root->val);
        lvl++;
        if(root->left != NULL){
            root->left->val = root->val*2+1;
        }
        if(root->right != NULL){
            root->right->val = root->val*2+2;
        }
        dfs(root->left);
        dfs(root->right);
    }
    FindElements(TreeNode* root) {
        dfs(root);
    }
    
    bool find(int target) {
        if(hasValue.find(target) != hasValue.end())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */