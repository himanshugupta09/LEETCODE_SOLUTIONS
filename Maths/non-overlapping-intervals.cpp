class Solution {
public:

    bool comp(vector<int>& a,vector<int>& b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        //sort(intervals.begin(),intervals.end(),comp);
        sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      return a[1] < b[1];
                  });

        int let = intervals[0][1];

        int cnt = 0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] < let)
            {
                cnt++;
            }
            else
            {
                let = intervals[i][1];
            }
            
        }
        return cnt;
    }
};
