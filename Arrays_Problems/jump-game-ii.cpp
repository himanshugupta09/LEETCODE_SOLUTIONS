class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size()-1;
        
        int cnt = 0;
        int far = 0;
        int cur = 0;


       for(int j=0;j<nums.size()-1;j++)
       {
           far = max(far,nums[j]+j);

           if(j == cur)
           {
               cur = far;
               cnt++;
           }

       }
       return cnt;

        return cnt;
    }
};
