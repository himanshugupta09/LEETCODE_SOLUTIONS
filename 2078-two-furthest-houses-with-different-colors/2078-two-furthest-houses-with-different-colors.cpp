class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        
        int maxDis = 0;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(colors[i] != colors[j])
                {
                    maxDis = max(maxDis,(j-i));
                }
            }
        }
        return maxDis;
        
    }
};