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
bool comp1(const pair<int, int>& a, const pair<int, int>& b)

    {

        if(a.second<b.second)

            return true;

        else if(a.second == b.second)

        {

            return a.first<b.first;

        }

        return false;

    }

class Solution {

public:

    

    

    

     map<int, vector<pair<int, int>>> mp;

    

    void inorder(TreeNode* root, int level, int row)

    {

        if(root == NULL)

            return;

        inorder(root->left, level-1, row+1);

        mp[level].push_back({root->val, row+1});

        inorder(root->right, level+1, row+1);

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

       

        vector<vector<int>> ans;

        if(root == NULL)

            return ans;

        inorder(root, 0, 0);

        for(auto Item : mp)

        {

            sort(Item.second.begin(), Item.second.end(), comp1);

            vector<int> a;

            for(auto ele : Item.second)

                a.push_back(ele.first);

            ans.push_back(a);

        }

        return ans;

    }

};
        
   
