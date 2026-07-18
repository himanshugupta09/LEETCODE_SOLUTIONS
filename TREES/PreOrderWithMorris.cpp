/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
         vector<int> res;
    while (root) {
        
        // If left child is null, store the current node
        // data and move to right child
        if (root->left == nullptr) {
            res.push_back(root->data);
            root = root->right;
        }
        else {
            
            // Find inorder predecessor
            Node* current = root->left;
            while (current->right && current->right != root)
                current = current->right;

            // If the right child of inorder predecessor
            // already points to this node
            if (current->right == root) {
                current->right = nullptr;
                root = root->right;
            }
            
            // If right child doesn't point to this node
            else {
                res.push_back(root->data);  
                current->right = root;
                root = root->left;
            }
        }
    }
    return res;
    }
};