/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>res;
        Node* curr = root;
        
        while(curr != nullptr)
        {
            if(curr->left == NULL)
            {
                res.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node * pred = curr->left;
                while(pred->right != nullptr && pred->right != curr)
                {
                    pred = pred->right;
                }
                if(pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    res.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};