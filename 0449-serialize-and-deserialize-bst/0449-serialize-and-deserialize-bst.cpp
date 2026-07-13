/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int idx;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        idx = 0;

        vector<int> preorder;

        stringstream ss(data);
        string temp;

        while(getline(ss,temp,',')) {
            preorder.push_back(stoi(temp));
        }

        return buildTree(preorder, INT_MIN, INT_MAX);
    }
private:
    TreeNode* buildTree(vector<int>&nums, int low, int high)
    {
        if(idx == nums.size())
        {
            return nullptr;
        }
        if((nums[idx]) < low || (nums[idx]) > high)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(nums[idx++]);
        root->left = buildTree(nums,low,root->val);
        root->right = buildTree(nums,root->val,high);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;