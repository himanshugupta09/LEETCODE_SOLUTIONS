class Solution {
  public:
    vector<int>nextSmaller(vector<int>&arr){
      
      int n=arr.size();
      vector<int>res(n);
      stack<int>st;
      for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[st.top()]>=arr[i]){
              st.pop();
          }
          if(!st.empty()) res[i]=st.top();
          else res[i]=n;
          st.push(i);
      }
      return res;
  }
    vector<int>prevSmaller(vector<int>&arr){
      
      int n=arr.size();
      vector<int>res(n);
      stack<int>st;
      for(int i=0;i<n;i++){
          while(!st.empty() && arr[st.top()]>arr[i]){
              st.pop();
          }
          if(!st.empty()) res[i]=st.top();
          else res[i]=-1;
          st.push(i);
      }
      return res;
  }
    int sumSubMins(vector<int> &arr) {
        int mod = 1e9 + 7;
        int totalSum = 0;
        int n = arr.size();
        
        vector<int>nex=nextSmaller(arr);
        vector<int>pre=prevSmaller(arr);
        
        for(int ii = 0; ii < n; ++ii)
        {
            int left = ii - pre[ii];
            int right = nex[ii] - ii;
            totalSum = (totalSum + (left * right * arr[ii] * 1LL)%mod)%mod;
        }
        return totalSum;
    }
};
