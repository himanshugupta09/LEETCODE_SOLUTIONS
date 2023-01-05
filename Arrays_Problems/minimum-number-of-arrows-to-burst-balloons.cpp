class Solution {
public:

    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end());
        int reqArrows = 1;

        int initialMin = points[0][1];

        for(auto p:points)
        {
            if(p[0] > initialMin)
            {
                reqArrows++;
                initialMin = p[1];

            }
            initialMin = min(initialMin,p[1]);
        }

        return reqArrows;
    }
};
