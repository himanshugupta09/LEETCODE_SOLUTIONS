class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int pro = nums[i]*nums[j];
                
                    mpp[pro]++;
                
                
            }
        }
        for(auto i:mpp)
        {
            int pairE = (i.second-1)*i.second/2;
            res += 8*pairE;
        }
        return res;

    }
};