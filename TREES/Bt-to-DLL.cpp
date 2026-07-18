/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    Node* treeToDLL(Node* root) {
        if (!root)
            return nullptr;
    
        stack<Node*> stk;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
    
        while (root || !stk.empty()) {
    
            while (root) {
                stk.push(root);
                root = root->left;
            }
    
            root = stk.top();
            stk.pop();
    
            prev->right = root;
            root->left = prev;
            prev = root;
    
            root = root->right;
        }
    
        Node* head = dummy->right;
        head->left = nullptr;
        prev->right = nullptr;
    
        delete dummy;
        return head;
    }
};