class Solution {
public:
    /*
    int findMaxK(vector<int>& nums) {
        unordered_set<int>a(nums.begin(),nums.end());
        
        //This Approach works using Hash Table 
        
        int res = INT_MIN; 
        for(int num:nums)
        {
            if(a.find((0-num)) != a.end())
            {
                res = max(res,num);
            }
            //a.insert(num);
        }
        if(res != INT_MIN){
            return res;
        }
        return -1;
    }
    */
    
    //This is Two pointer
    /*
    int findMaxK(vector<int>& nums) {
        //This approach is usinng sorting + two-pointer
        // firstly sort Whole array in oncreasing order
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        
        while(lo < hi)
        {
            if(-nums[lo] == nums[hi])
            {
                return nums[hi];
            }
            else if(-nums[lo] > nums[hi])
            {
                ++lo;
            }
            else
            {
                --hi;
            }
        }
        return -1;
        
    }
    */
    int findMaxK(vector<int>& nums) {
        int res = -1;
        unordered_set<int>s;
        for(int num:nums)
        {
            const int ab = abs(num);
            if(ab > res && s.contains(-num)) res = ab;
            s.insert(num);
        }
        return res;
        
    }
};
