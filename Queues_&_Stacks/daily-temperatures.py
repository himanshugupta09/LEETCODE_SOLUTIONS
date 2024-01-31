class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int>s;
        int n = temperatures.size();
        vector<int>res(n,0);

        for(int i=0;i<n;i++)
        {
            while(!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                int now = s.top();
                s.pop();
                res[now] = i-now;

            }
            s.push(i);
        }
        return res;
    }
};
