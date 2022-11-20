class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int ans = 0;
        
        int mx = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] > mx)
            {
                mx = max(mx,arr[i]);
                
            }
            if(mx == i)
            {
                ans++;
                
            }
            
        }
        
        
        
        return ans;
        
    }
};
