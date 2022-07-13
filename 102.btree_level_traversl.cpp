class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
	if(root==NULL)
        return {};
        
	queue<TreeNode*> q;
	vector<vector<int> > ans;
        
	q.push(root);
        
	while(!q.empty()) {
		int levelSize = size(q);
		vector<int> currentLevel;
		for(int i = 0; i < levelSize; i++) {
			auto top = q.front(); q.pop();
			if(top -> left) q.push(top -> left);
			if(top -> right) q.push(top -> right);
			currentLevel.push_back(top -> val);
		}
		ans.push_back(currentLevel);
	}
	return ans;
}
};
