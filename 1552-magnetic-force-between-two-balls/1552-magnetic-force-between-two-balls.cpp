class Solution {
public:
    bool canPlace(vector<int>&positions,int mid,int m)
    {
        int count = 1;
        int lastPlaced = positions[0];
        for(int i=1;i<positions.size();i++)
        {
            if(abs(lastPlaced-positions[i]) >= mid)
            {
                lastPlaced = positions[i];
                count++;
            }
            if(count >= m) return true;
        }
        return count >= m;

    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        long long ans = -1;
        long long low = 1;
        int n = position.size();
        long long  high = position[n-1]-position[0];
        
        while(low <= high)
        {
            long long mid = low + (high-low)/2;
            if(canPlace(position,mid,m))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};