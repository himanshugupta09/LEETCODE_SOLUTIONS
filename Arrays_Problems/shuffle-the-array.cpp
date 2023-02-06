class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
      vector<int>a;

      for(int i=n;i<2*n;i++)
      {
          a.push_back(nums[i]);
      }

      nums.resize(n);
      int j = 0;

      for(int i=0;i<2*n;i++)
      {
          if(i%2 != 0)
          {
              nums.insert(nums.begin()+i,a[j]);
              j++;
          }
      }
    return nums;
        
    }
};
