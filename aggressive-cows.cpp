class Solution {
  public:
    bool canPlace(vector<int>&stalls,int k,int dist)
    {
        int count = 1;
        int last = stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-last >= dist)
            {
                count++;
                last = stalls[i];
            }
            if(count >= k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int left = 1;
        int right = stalls[n-1]-stalls[0];
        int distance = 0;
        while(left <= right)
        {
            int mid = (right+left)/2;
            if(canPlace(stalls,k,mid))
            {
                distance = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
            
        }
        return distance;
    }
};
