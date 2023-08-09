//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

int sumLeaf(Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumLeaf(root)<<endl;
  }
  return 0;
}

// } Driver Code Ends


/*Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node *left, *right;
};*/
// function should return the sum of all the 
// leaf nodes of the binary tree 
// void dfs(Node* root,int &sum)
// {
//     // check if the current node we are at is Leaf if it is then add node's value to sum and return
//     if(root->left == NULL && root->right == NULL)
//     {
//         sum += root->data;
//         return;
//     }
//     dfs(root->left,sum); // call for left subtreee
//     dfs(root->right,sum); // call for right subtree
    
// }
int res = 0;
int sumLeaf(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return sumLeaf(root->left) + sumLeaf(root->right);
    }
    
}
