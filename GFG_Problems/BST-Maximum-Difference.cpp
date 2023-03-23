//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   
        // Code here
         int fs=0 ,ls=1e9 ;
          Node* ptr=NULL ; 
          void cal(Node* root ,int tar , int sum)
          {
              if(root==NULL)return ;
              
              if(root->data==tar)
              {
                  fs=sum , ptr = root ;
                  return;
              }
              if(tar<=root->data)
              cal(root->left ,tar ,sum+root->data); 
              else
              cal(root->right ,tar ,sum+root->data);
          }
          
          void solve(Node* ptr ,int sum )
          {
              if(ptr==NULL)
              return;
              if(ptr->left==NULL && ptr->right==NULL)
              {
                  ls = min(ls,sum+ptr->data); 
                  return; 
              }
              
              solve(ptr->left, sum+ptr->data) ;
              solve(ptr->right, sum+ptr->data) ;
          }
          
          
    int maxDifferenceBST(Node *root,int target){
        // Code here
        if(root==NULL)return -1 ;
        
        cal(root ,target ,0 ) ;
        
        if(ptr==NULL)
        return -1 ;
        
        solve(ptr , 0 ) ;
        // cout << fs << " "<< ls << endl;
        return fs-ls+target;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
