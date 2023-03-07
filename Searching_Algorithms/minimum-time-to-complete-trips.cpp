class Solution {
public:

    bool enoughTime(vector<int>& time,long long given,int totalTrips)
    {
        long long act = 0;
        for(int i:time)
        {
            act += given/i;
        }

        return act >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
       
        
        long long left = 1,right = 1LL**max_element(time.begin(),time.end())*totalTrips;

        while(left < right)
        {
            long long mid = (left+right)/2;

           
            if(enoughTime(time,mid,totalTrips))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }

        

        return left;

    }
};
