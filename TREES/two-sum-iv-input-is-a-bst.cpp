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
    
    vector<int> nums;
    
    void sumChecker(TreeNode* root)
    {
        if(!root)
        {
            return;
            
        }
        sumChecker(root->left);
        nums.push_back(root->val);
        sumChecker(root->right);
        
        
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        sumChecker(root);
        
        int st = 0,en = nums.size()-1;
        
        while(st < en)
        {
            if(nums[st] + nums[en] == k)
            {
                return true;
            }
            else if(nums[st] + nums[en] < k)
            {
                st++;
            }
            else{
                en--;
                
            }
        }
        return false;
        
    }
};
