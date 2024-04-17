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
    string univ = "abcdefghijklmnopqrstuvwxyz";
    //vector<string>s;
    string smallest;
    void trav(TreeNode* root,string st)
    {
        st = univ[root->val] + st;
        
        if(!root->left && !root->right)
        {
            //st.push_back(univ[root->val]);
            //string t = st;
            //reverse(t.begin(),t.end());
            //s.push_back(t);
            if(smallest == "" || st < smallest)
            {
                smallest = st;
            }
            //st.pop_back();
            return;
        }
        if(root->left)
        {
            //st.push_back(univ[root->val]);
            trav(root->left,st);
            
        }
        if(root->right)
        {
            //st.push_back(univ[root->val]);
            trav(root->right,st);
            
        }
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string t;
        trav(root,t);
        //sort(s.begin(),s.end());
        return smallest;
    }
};
