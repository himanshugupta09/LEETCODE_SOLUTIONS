class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        unordered_map<int,int>mpp;
        for(int i:arr)
        {
            mpp[i]++;
        }
        stack<int>stk;
        stk.push(-1);
        vector<int>res(arr.size(),-1);
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(stk.top() != -1 && mpp[stk.top()] <= mpp[arr[i]])
            {
                stk.pop();
            }
            if(!stk.empty())
            {
                res[i] = stk.top();
            }
            stk.push(arr[i]);
        }
        return res;
    }
};
