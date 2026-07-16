class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int i=0;
        int j=0;
        int maxRooms = 0;
        int rooms = 0;
        int last = -1;
        int n = start.size();
        while(i < n)
        {
            if(start[i] < end[j])
            {
                rooms++;
                i++;
            }
            else
            {
                j++;
                rooms--;
            }
            if(rooms < 0)
            {
                rooms = 0;
            }
            maxRooms = max(maxRooms,rooms);
        }
        return maxRooms;
    }
};
