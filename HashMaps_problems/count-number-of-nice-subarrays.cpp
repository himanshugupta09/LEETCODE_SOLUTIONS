class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int csm = 0,sub = 0;
        unordered_map<int,int>pres;
        pres[0] = 1;
        
        for(int i=0;i<n;i++)
        {
            csm += nums[i]%2;
            if(pres.find(csm-k) != pres.end())
            {
                sub += pres[csm-k];
            }
            pres[csm]++;
        }
        return sub;
    }
};
