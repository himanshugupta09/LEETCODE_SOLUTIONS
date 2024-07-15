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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> isChild;
        unordered_map<int, TreeNode*> mp;
        int rot = -1;

        for (const auto& desc : descriptions) {
            int par = desc[0];
            int child = desc[1];
            int isLeft = desc[2];
            
            if(mp.find(par) == mp.end())
            {
                mp[par] = new TreeNode(par);
            }
            if(mp.find(child) == mp.end())
            {
                mp[child] = new TreeNode(child);
            }
            
            if(isLeft)
            {
                mp[par]->left = mp[child];
            }
            else
            {
                mp[par]->right = mp[child];
            }
            isChild.insert(child);
        }
        TreeNode* root = nullptr;
        for (const auto& node : mp) {
            if (isChild.find(node.first) == isChild.end()) {
                root = node.second;
                break;
            }
        }
        

        return root;
    }
};
