class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum = 0;
        int k = 0;
        vector<int>dif(n+1);
        for(int i=0;i<n;i++)
        {
            while(sum+dif[i] < nums[i])
            {
                k++;
                if(k > queries.size()) return -1;
                int left = queries[k-1][0],right = queries[k-1][1],val = queries[k-1][2];
                if(right >= i)
                {
                    dif[max(left,i)] += val;
                    dif[right+1] -= val;
                }
            }
            sum += dif[i];
        }
        return k;
    }
};