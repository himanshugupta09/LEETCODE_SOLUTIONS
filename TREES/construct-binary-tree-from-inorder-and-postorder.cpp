//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    Node* build(vector<int>& in, int is, int ie, vector<int>& post, int ps, int pe, unordered_map<int,int>& mp)
    {
        if(ps > pe || is > ie)
        {
            return NULL;
        }
        Node* root = new Node(post[pe]);
        int inR = mp[post[pe]];
        int numsLeft = inR - is;
    
        root->left = build(in, is, inR - 1, post, ps, ps + numsLeft - 1, mp);
        root->right = build(in, inR + 1, ie, post, ps + numsLeft, pe - 1, mp);
    
        return root;
    }

    Node* buildTree(int in[], int post[], int n) {
        vector<int> inorder(in, in + n);
        vector<int> postorder(post, post + n);
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
    
        return build(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }

};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
