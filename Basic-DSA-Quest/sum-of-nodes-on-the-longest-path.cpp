/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int max_len,max_sum;
    void traverse(Node *root,int len,int sum)
    {
        if(!root)
        {
            return;   
        }
        len++;
        sum += root->data;
        if(!root->left && !root->right)
        {
            if(len > max_len)
            {
                max_sum = sum;
                max_len = len;
            }
            else if(max_len == len)
            {
                max_sum = max(max_sum,sum);
            }
            return;
        }
        traverse(root->left,len,sum);
        traverse(root->right,len,sum);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        max_sum = 0,max_len = 0;
        traverse(root,0,0);
        
        return max_sum;
    }
};
