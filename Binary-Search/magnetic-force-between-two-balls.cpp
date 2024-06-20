class Solution {
public:
    bool solve(int x,int m,vector<int>&pos)
    {
        int pre = pos[0];
        int ballp = 1;
        
        for(int i=1;i<pos.size() && ballp < m;i++)
        {
            int cur = pos[i];
            if(cur-pre >= x)
            {
                ballp += 1;
                pre = cur;
            }
        }
        return ballp == m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int lo = 1;
        int hi = ceil(position[n-1]/(m-1.0));
        int res = 0;
        
        while(lo <= hi)
        {
            int mid  = lo + (hi-lo)/2;
            
            if(solve(mid,m,position))
            {
                res = mid;
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
            
        }
        return res;
    }
};
