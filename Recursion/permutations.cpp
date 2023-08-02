class Solution {
public:
    vector<vector<int>>res;
    void getPermutations(vector<int> nums,vector<int> &temp,vector<bool> &taken)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
           if(!taken[i])
           {
               taken[i] = 1;
               temp.push_back(nums[i]);
                getPermutations(nums,temp,taken);
                temp.pop_back();
                taken[i] = 0;
           }

        }

        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 1)
        {
            return {{nums[0]}};
        }
        vector<bool>taken(n);
        vector<int>temp;
        getPermutations(nums,temp,taken);
        return res;

    }
};
