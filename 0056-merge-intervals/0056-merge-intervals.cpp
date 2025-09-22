class Solution {
public:
    static bool checker(vector<int>a,vector<int>b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        sort(intervals.begin(),intervals.end(),checker);
        int i = 0;
        int n = intervals.size();
        while(i < n)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i;
            while(j < intervals.size() && intervals[j][0] <= end)
            {
                end = max(end,intervals[j][1]);
                j++;
            }
            i = j;
            mergedIntervals.push_back({start,end});
        }
        return mergedIntervals;
    }
};