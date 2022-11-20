class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        // base case
        if(root == NULL){
            return ans;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* node = q.front();
                q.pop();
                vector<Node*> v = node->children;
                temp.push_back(node->val);
                for(auto i : v){
                    q.push(i);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
