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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mpp;        
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty())
        {
            int ln = q.size();
            auto [node, p] = q.front();
            q.pop();

            int col = p.first;
            int row = p.second;

            mpp[col][row].insert(node->val);

            if(node->left)
                q.push({node->left,{col-1,row+1}});

            if(node->right)
                q.push({node->right,{col+1,row+1}});
        }
        vector<vector<int>>res;
        for(auto &col : mpp)
        {
            vector<int> temp;
            for(auto &row : col.second)
            {
                temp.insert(temp.end(),
                            row.second.begin(),
                            row.second.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};