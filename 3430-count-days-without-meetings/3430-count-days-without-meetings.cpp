class Solution {
public:
    
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        
        int n = meetings.size();
        int freeD = 0,last = 0;

        for(int i=0;i<n;i++)
        {
            int st = meetings[i][0],end = meetings[i][1];
            if(st > last+1)
            {
                freeD += st-last-1;
            }
            last = max(last,end);
        }
        freeD +=  days-last;
        return freeD;

    }
};