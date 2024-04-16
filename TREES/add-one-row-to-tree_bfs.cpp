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
//     void trav(TreeNode* root,int d,int val,int depth)
//     {
//         if(d == depth)
//         {
            
//         }

//     }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if (depth == 1) {
        TreeNode* newRoot = new TreeNode(val);
        newRoot->left = root;
        root = newRoot;
    } else {
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        
        while (!q.empty() && d < depth - 1) {
            int n = q.size();
            d++;
            
            for (int i = 0; i < n; i++) {
                TreeNode* f = q.front();
                q.pop();
                
                if (f->left) {
                    q.push(f->left);
                }
                if (f->right) {
                    q.push(f->right);
                }
            }
        }
        
        while (!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            
            TreeNode* leftNode = f->left;
            TreeNode* rightNode = f->right;
            
            f->left = new TreeNode(val);
            f->right = new TreeNode(val);
            
            f->left->left = leftNode;
            f->right->right = rightNode;
        }
    }
    return root;
        
    }
};
