class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minH;
        int n = arr.size();
        vector<int>res(n,-1);
        
        for(int i=0;i<n;i++)
        {
            minH.push(arr[i]);
            if(minH.size() > k)
            {
                minH.pop();
            }
            if(minH.size() < k)
            {
                continue;
            }
            else{
                res[i] = minH.top();
            }
        }
        return res;
    }
};