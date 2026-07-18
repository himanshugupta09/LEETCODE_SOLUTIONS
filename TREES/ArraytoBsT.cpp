/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* build(vector<int>&nums,int left,int right)
    {
        if(left > right)
        {
            return nullptr;
        }
        int mid = left + (right-left)/2;
        Node* root = new Node(nums[mid]);
        root->left = build(nums,left,mid-1);
        root->right = build(nums,mid+1,right);
        
        return root;
    }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        return build(arr,0,arr.size()-1);
        
        
    }
};