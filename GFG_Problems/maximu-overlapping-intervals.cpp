class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        vector<int>st(n);
        vector<int>en(n);
        for(int i=0;i<n;i++)
        {
            st[i] = arr[i][0];
            en[i] = arr[i][1];
            
        }
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());
        int res = 0;
        int cur = 0;
        int i=0,j=0;
        while(i < n && j < n)
        {
            if(st[i] <= en[j])
            {
                cur++;
                res = max(res,cur);
                i++;
            }
            else
            {
                cur--;
                j++;
            }
        }
        return res;
    }
};
