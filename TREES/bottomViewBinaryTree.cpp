/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        map<int,int>mpp;
        while(!q.empty())
        {
            auto [node,axis] = q.front();
            q.pop();
            if(mpp.find(axis) == mpp.end())
                {
                    mpp[axis] = node->data;
                }
                else
                {
                    mpp[axis] = node->data;
                }
                if(node->left)
                {
                    q.push({node->left,axis-1});
                }
                if(node->right)
                {
                    q.push({node->right,axis+1});
                }
            
        }
        vector<int>res;
        for(auto i:mpp)
        {
            res.push_back(i.second);
        }
        return res;
        
    }
};