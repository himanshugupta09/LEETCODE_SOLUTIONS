/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    int maxSum = INT_MIN;
    int solve(Node* root)
    {
        if(!root)
        {
            return INT_MIN;
        }
        if(!root->left && !root->right)
        {
            return root->data;
        }
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        if(leftSum == INT_MIN)
        {
            return root->data+rightSum;
        }
        if(rightSum == INT_MIN)
        {
            return root->data+leftSum;
        }
        maxSum = max(maxSum,(root->data + leftSum + rightSum));
        return root->data + max(leftSum,rightSum);
    }
    int maxPathSum(Node *root) {
        // code here
        solve(root);
        return maxSum == INT_MIN ? -1 : maxSum;
    }
};