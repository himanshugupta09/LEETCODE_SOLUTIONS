/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool isDeadEnd(Node *root) {
        // Code here
        set<int>stt;
        vector<int>leafs;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* fr = q.front();
                q.pop();
                if(fr->left)
                {
                    q.push(fr->left);
                }
                if(fr->right)
                {
                    q.push(fr->right);
                }
                if(!fr->left && !fr->right)
                {
                    leafs.push_back(fr->data);
                }
                
                stt.insert(fr->data);
            }
        }
        for(int N:leafs)
        {
            if((N == 1 && stt.find(2) != stt.end())||((stt.find(N+1) != stt.end())&&(stt.find(N-1) != stt.end())))
            {
                return true;
            }
        }
        return false;
    }
};
