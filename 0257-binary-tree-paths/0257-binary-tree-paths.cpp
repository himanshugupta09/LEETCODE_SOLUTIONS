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
    vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> ans;
	stack<pair<TreeNode*, string>> s;
	s.push({ root,to_string(root->val) });

	while (!s.empty()) {
		pair<TreeNode*, string> cur = s.top(); s.pop();

		if (cur.first->left == nullptr && cur.first->right == nullptr) {
			ans.push_back(cur.second);
		}

		if (cur.first->left != nullptr) {
			string tmp = cur.second + "->" + to_string(cur.first->left->val);
			s.push({ cur.first->left,tmp });
		}
		if (cur.first->right != nullptr) {
			string tmp = cur.second + "->" + to_string(cur.first->right->val);
			s.push({ cur.first->right,tmp });
		}
	}
	return ans;

}
};