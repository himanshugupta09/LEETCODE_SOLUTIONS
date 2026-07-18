class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int>stk;
        vector<int>res(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && arr[stk.top()] > arr[i])
                {
                    res[stk.top()] = arr[i];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return res;
        
    }
};