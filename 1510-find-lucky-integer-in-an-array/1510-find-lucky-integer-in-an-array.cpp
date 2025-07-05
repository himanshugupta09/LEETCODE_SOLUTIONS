class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto i:arr)
        {
            mpp[i]++;
        }
        int maxy = INT_MIN;
        for(auto i:mpp)
        {
            if(i.first == i.second)
            {
                maxy =  max(maxy,i.first);
            }
        }
        return maxy == INT_MIN ? -1 : maxy;
        
    }
};