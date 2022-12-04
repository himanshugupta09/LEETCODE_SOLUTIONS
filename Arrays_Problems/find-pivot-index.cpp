class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        

        int rsm = 0;

        for(int i=0;i<nums.size();i++)
        {
            rsm += nums[i];
        }

        int id = -1;
        int ls = 0;

        for(int i=0;i<nums.size();i++)
        {
            ls += nums[i];
            
            

            if(ls == rsm)
            {
                id = i;
                break;
            }
            else{
                rsm -= nums[i];
            }

        }

        return id;
    }
};
