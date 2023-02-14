class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        
      long long sum = 0;
      while(nums.size() > 1)
      {
          string st = to_string(nums[0]) + to_string(nums[nums.size()-1]);
          sum += stoi(st);
          nums.pop_back();
          nums.erase(nums.begin());
      }
       
      if(nums.size() >= 1)
      {
          sum += nums[0];
      }
        
        return sum;
        
    }
};
