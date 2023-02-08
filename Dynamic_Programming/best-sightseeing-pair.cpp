class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
       int maxi = values[0] + 0;

       int ans = 0;

       for(int i=1;i<values.size();i++)
       {
           ans = max(ans,values[i]-i+maxi);
           maxi = max(maxi,values[i]+i);
       }
        return ans;

    }
};
