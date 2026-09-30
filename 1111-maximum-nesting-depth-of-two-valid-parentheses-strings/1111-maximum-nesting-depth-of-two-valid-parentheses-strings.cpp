class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        stack<int> stk;
        int n = s.size();
        vector<int> res(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                res[i] = stk.size() % 2;
                stk.push(i);
            }
            else
            {
                res[i] = res[stk.top()];
                stk.pop();
            }
        }

        return res;
    }
};
