class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int maxGap = INT_MIN;
        
        for(int i=0;i<points.size()-1;i++)
        {
            int a = points[i][0];
            int b = points[i+1][0];
            
            int ar = b-a;
            maxGap = max(ar,maxGap);
        }
        return maxGap;
    }
};
