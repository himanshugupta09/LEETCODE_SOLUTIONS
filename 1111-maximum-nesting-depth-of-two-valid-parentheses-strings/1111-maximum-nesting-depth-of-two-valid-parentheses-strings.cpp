class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        stack<int> stk;
        int n = s.size();
        vector<int> res(n, -1);
        /*
        Space Optimized to O(1)
        */
        int dep = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                dep++;
                res[i] = dep%2;
            }
            else
            {
                res[i] = dep%2;
                dep--;
            }
        }

        return res;
    }
};
