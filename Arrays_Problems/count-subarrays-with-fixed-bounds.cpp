class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

     long long res = 0;
     int min_k = -1;
     int max_k = -1;
     int lb = -1;

     for(int i=0;i<nums.size();i++)
     {
         if(nums[i] == minK)
         {
             min_k = i;
         }
         if(nums[i] == maxK)
         {
             max_k = i;
         }
         if(nums[i] > maxK || nums[i] < minK)
         {
             lb = i;
         }

         res += max(0, min(min_k,max_k) - lb);
     }   

     return res;
    }
};
