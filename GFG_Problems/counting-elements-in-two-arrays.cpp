class Solution {
  public:
    int binaryCounter(vector<int>&b,int ele)
    {
        int low = 0,high = b.size()-1;
        int res = 0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(b[mid] <= ele)
            {
                res++;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return res;
    }
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(),b.end());
        vector<int>res;
        
        for(auto ele:a)
        {
            int count = upper_bound(b.begin(),b.end(),ele) - b.begin();
            
            res.push_back(count);
        }
        return res;
        
    }
};
