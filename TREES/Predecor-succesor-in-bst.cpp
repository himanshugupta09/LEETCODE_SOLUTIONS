class Solution {
public:
    Node* pred = nullptr;
    Node* succ = nullptr;
    int gdiff = INT_MAX;
    int ldiff = INT_MAX;

    void solve(Node* root, int key)
    {
        if (!root)
            return;

        if (root->data > key)
        {
            int d = root->data - key;
            if (d < gdiff)
            {
                gdiff = d;
                succ = root;
            }
            solve(root->left, key);      // FIX 1: go left
        }
        else if (root->data < key)
        {
            int d = key - root->data;
            if (d < ldiff)
            {
                ldiff = d;
                pred = root;
            }
            solve(root->right, key);     // correct
        }
        else
        {
            // predecessor = maximum in left subtree
            Node* t = root->left;
            while (t)
            {
                pred = t;
                t = t->right;
            }

            // successor = minimum in right subtree
            t = root->right;
            while (t)
            {
                succ = t;
                t = t->left;
            }
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        solve(root, key);
        return {pred, succ};
    }
};