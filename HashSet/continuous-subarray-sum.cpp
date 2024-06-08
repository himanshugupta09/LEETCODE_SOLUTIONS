/*
With Hashmap
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int preMod = 0;
        map<int,int>mp;
        mp[0] = -1;
        
        for(int i=0;i<n;i++)
        {
            preMod = (preMod+nums[i])%k;
            if((mp.find(preMod) != mp.end()))
            {
                if(i-mp[preMod] > 1)return true;
            }
            else{
                mp[preMod]=i;
            }
        }
        return false;
    }
};
*/

// Below is using HashSet
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
       set<int>hash;
        
        int sm = 0,pre;
        
        for(int i=0;i<n;i++)
        {
            pre = sm;
            sm = (sm+nums[i])%k;
            if(hash.find(sm) != hash.end())
            {
                return true;
            }
            hash.insert(pre);
        }
        return false;
    }
};
