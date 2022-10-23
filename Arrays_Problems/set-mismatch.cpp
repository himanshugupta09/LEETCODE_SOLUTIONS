 // =========================================> APPROACH 1 ::-->    USING HASHMAP <=====================================================================================
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        
        int a = 0,u = 0;
        
        
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
       
        
        
        
        
        
       
        for(int i=1;i<=nums.size();i++)
        {
            if(mp[i] == 2)
            {
                a = i;
                
            }
            else if(mp[i] == 0)
            {
                u = i;
            }
            
        }
        
        
        
        
        return {a,u};
        
    }
};



// ============================================================= APPROACH 2 ::-> USING BIT MANIPULATION <==============================================================


static vector<int> findErrorNums(const vector<int>& nums) {
        const int n = size(nums);
        vector<bool> seen(n + 1);
        int dup = -1;
        for (int num : nums) {
            if (seen[num]) dup = num;
            seen[num] = true;
        }
        int miss = -1;
        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                miss = i;
                break;
            }
        }
        return {dup, miss};
    }




// ============================================================ APPROACH 3 :::-> USING SORT AND SCAN <=================================================================



static vector<int> findErrorNums(vector<int>& nums) {
        const int n = size(nums);
        // If we don't want to modify the input permanently we would need to make a copy here.
        sort(begin(nums), end(nums));
        int dup = -1;
        int miss = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == nums[i]) {
                dup = nums[i];
            } else if (nums[i - 1] + 1 < nums[i]) {
                miss = nums[i - 1] + 1;
            }
        }
        return {dup, nums.back() != n ? n : miss};
    }





//  ================================================================= APPROACH 4 ::-> USING THE MATHS <================================================================



static vector<int> findErrorNums(const vector<int>& nums) {
        long diff = 0;
        long square_diff = 0;
        for (int i = 0; i < size(nums); ++i) {
            diff += i + 1 - nums[i];
            square_diff += (i + 1) * (i + 1) - nums[i] * nums[i];
        }
        long s = square_diff / diff;
        const int dup = (s - diff) / 2;
        const int miss = (s + diff) / 2;
        return {dup, miss};
    }
