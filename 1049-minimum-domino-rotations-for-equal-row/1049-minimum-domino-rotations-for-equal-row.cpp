class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> f(7),b(7),same(7);
        int n = tops.size();
        
        for(int i=0;i<n;i++)
        {
            ++f[tops[i]];
            ++b[bottoms[i]];
            
            if(tops[i] == bottoms[i])
            {
                ++same[tops[i]];
            }
            
            
        }
        int min_rot = INT_MAX;
        
        for(int i=0;i<7;i++)
        {
            if(f[i] + b[i]-same[i] == n)
            {
                min_rot = min(min_rot,min(f[i],b[i]) - same[i]);
            }
        }
        
        return min_rot == INT_MAX?-1:min_rot;
        
    }
};