class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mpp;
        for(int i:answers) mpp[i]++;
        int res = 0;
        for(auto p:mpp)
        {
            res += ceil((double)p.second/(p.first+1))*(p.first+1);
        }
        return res;
    }
};