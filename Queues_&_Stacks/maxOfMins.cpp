class Solution {
  public:
  vector<int> nextSmaller(vector<int>& arr)
{
    int n = arr.size();
    stack<int> stk;
    vector<int> next(n, n);

    for(int i = n-1; i >= 0; i--)
    {
        while(!stk.empty() && arr[stk.top()] >= arr[i])
        {
            stk.pop();
        }

        if(!stk.empty())
            next[i] = stk.top();

        stk.push(i);
    }

    return next;
}


vector<int> prevSmaller(vector<int>& arr)
{
    int n = arr.size();
    stack<int> stk;
    vector<int> prev(n, -1);

    for(int i = 0; i < n; i++)
    {
        while(!stk.empty() && arr[stk.top()] >= arr[i])
        {
            stk.pop();
        }

        if(!stk.empty())
            prev[i] = stk.top();

        stk.push(i);
    }

    return prev;
}
    vector<int> maxOfMins(vector<int>& arr) 
{
    int n = arr.size();

    vector<int> res(n+1, INT_MIN);

    vector<int> nextSm = nextSmaller(arr);
    vector<int> prevSm = prevSmaller(arr);

    for(int i = 0; i < n; i++)
    {
        int len = nextSm[i] - prevSm[i] - 1;
        res[len] = max(res[len], arr[i]);
    }

    for(int i = n-1; i >= 1; i--)
    {
        res[i] = max(res[i], res[i+1]);
    }

    vector<int> ans;

    for(int i = 1; i <= n; i++)
        ans.push_back(res[i]);

    return ans;
}
};