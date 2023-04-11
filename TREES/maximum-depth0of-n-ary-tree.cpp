/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {

        stack<pair<Node*,int>>stk;
        if(root)
        {
            stk.push({root,1});
        }
        int lvl = 0;

        while(!stk.empty())
        {
            Node* cur = stk.top().first;
            int depth_now = stk.top().second;
            stk.pop();

            for(Node* n:cur->children)
            {
                stk.push({n,depth_now+1});
            }
            lvl = max(lvl,depth_now);


        }
        return lvl;

        

        
    }
};
