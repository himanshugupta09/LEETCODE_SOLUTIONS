class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        stack<long long>stk;
        stk.push(-1);
        int n = arr.size();
        vector<int>res(arr.size(),-1);
        for(int i=2*n-1;i>=0;i--)
        {
            int idx = i % n;
            while (!stk.empty() && stk.top() <= arr[idx]) {
                stk.pop();
            }
            if (i < n) {
                res[idx] = stk.empty() ? -1 : stk.top();
            }
            stk.push(arr[idx]);
            
        }
        return res;
    }
};
