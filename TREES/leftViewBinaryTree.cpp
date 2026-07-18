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
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*>q;
        vector<int>res;
        if(!root)
        {
            return {};
        }
        q.push(root);
        while(!q.empty())
        {
           int l = q.size();
           bool first = false;
           for(int i=0;i<l;i++)
           {
               Node* fr = q.front();
               q.pop();
               if(!first)
               {
                   res.push_back(fr->data);
                   first = true;
               }
               if(fr->left)
               {
                   q.push(fr->left);
               }
               if(fr->right)
               {
                   q.push(fr->right);
               }
           }
        }
        return res;
    }
};