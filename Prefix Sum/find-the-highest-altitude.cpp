class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        vector<int>prefixSum;
        prefixSum.push_back(0);

        for(int i=0;i<gain.size();i++)
        {
            prefixSum.push_back(prefixSum[prefixSum.size()-1] + gain[i]);
        }

        return *max_element(prefixSum.begin(),prefixSum.end());
        
    }
};
