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
    unordered_map<int,vector<TreeNode*>> mp;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }

        std::vector<TreeNode*> v;

        if (n == 1) {
            v.push_back(new TreeNode(0));
        } else if (n % 2 == 1) {
            for (int x = 0; x < n; x++) {
                int y = n - 1 - x;

                vector<TreeNode*> xbft = allPossibleFBT(x);
                vector<TreeNode*> ybft = allPossibleFBT(y);

                for (int L = 0; L < xbft.size(); L++) {
                    for (int R = 0; R < ybft.size(); R++) {
                        TreeNode* newNode = new TreeNode(0);
                        newNode->left = xbft[L];
                        newNode->right = ybft[R];

                        v.push_back(newNode);
                    }
                }
            }

            mp[n] = v;
        }

        return v;
    }


};
