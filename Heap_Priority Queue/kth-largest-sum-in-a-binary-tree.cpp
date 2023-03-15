/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>pq;
        queue<TreeNode*>q;
        q.push(root);

        if(!root)
        {
            return -1;
        }
        while(!q.empty())
        {
            int n = q.size();
            long long sm = 0;

            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                sm += temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }

            }
            pq.push(sm);
        }
        if(pq.size() < k)
        {
            return -1;
        }
        k = k-1;
        while(k--)
        {
            pq.pop();
        }

        return pq.top();
    }
};
