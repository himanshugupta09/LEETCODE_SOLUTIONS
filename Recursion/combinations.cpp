class Solution {
public:
    vector<vector<int>>res;

    void getCombinations(int n,int tot,vector<int> &arr,int k)
    {
        if(arr.size() == k)
        {
            res.push_back(arr);
            return;
        }
        for(int i=n;i<=tot;i++)
        {
            arr.push_back(i);
            getCombinations(i+1,tot,arr,k);
            arr.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
      
      vector<int>arr;
      getCombinations(1,n,arr,k);
      return res;
    }
};
