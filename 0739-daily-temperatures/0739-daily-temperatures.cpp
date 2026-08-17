class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>stk;
        int n = temp.size();
        vector<int>res(n,0);

        for(int i=0;i<n;i++)
        {
             while(!stk.empty() && temp[stk.top()] < temp[i])
            {
                int tp = stk.top();
                stk.pop();
                res[tp] = i-tp;
            }
            stk.push(i);
        }
        return res;
    }
};