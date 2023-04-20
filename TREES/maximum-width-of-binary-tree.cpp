class Solution {
public:
    using ll = long long;
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> d; // <node, idx>
        // push the first element with idx = 0
        d.push({root, 0});
        // BFS
        while (!d.empty()) {
            // l_idx is the idx of the leftmost node
            // r_idx is the idx of the rightmost node
            ll l_idx = d.front().second, r_idx = d.back().second;
            // define n here outside as d.size() may be changed
            int n = (int) d.size();
            // iterate each tuple
            for (int i = 0; i < n; i++) {
                // get one tuple and pop it
                auto x = d.front(); d.pop();
                // get the idx of the current node
                auto idx = x.second ;
                // if it has the left node, push it for the next level
                // with idx = 2 * cur_idx
                if (x.first->left)  d.push({x.first->left, (ll) 2 * idx});
                // if it has the right node, push it for the next level
                // with idx = 2 * cur_idx + 1
                if (x.first->right) d.push({x.first->right, (ll) 2 * idx + 1});
            }
            // check if the current level got the max width
            ans = max(ans, int(r_idx - l_idx + 1));
        }
        return ans;
    }
};class Solution {
public:
    using ll = long long;
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> d; // <node, idx>
        // push the first element with idx = 0
        d.push({root, 0});
        // BFS
        while (!d.empty()) {
            // l_idx is the idx of the leftmost node
            // r_idx is the idx of the rightmost node
            ll l_idx = d.front().second, r_idx = d.back().second;
            // define n here outside as d.size() may be changed
            int n = (int) d.size();
            // iterate each tuple
            for (int i = 0; i < n; i++) {
                // get one tuple and pop it
                auto x = d.front(); d.pop();
                // get the idx of the current node
                auto idx = x.second ;
                // if it has the left node, push it for the next level
                // with idx = 2 * cur_idx
                if (x.first->left)  d.push({x.first->left, (ll) 2 * idx});
                // if it has the right node, push it for the next level
                // with idx = 2 * cur_idx + 1
                if (x.first->right) d.push({x.first->right, (ll) 2 * idx + 1});
            }
            // check if the current level got the max width
            ans = max(ans, int(r_idx - l_idx + 1));
        }
        return ans;
    }
};
