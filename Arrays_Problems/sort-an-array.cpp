class Solution {
public:
   vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto i:nums)
        {
            pq.push(i);

        }

       nums.erase(nums.begin(),nums.end());

        while(!pq.empty())
        {
            int n =  pq.top();
            pq.pop();
            nums.push_back(n);

        }

        return  nums;



    }
};
