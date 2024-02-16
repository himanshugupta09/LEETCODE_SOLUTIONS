class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        
        // Count the frequency of each integer in the array
        for(auto i : arr) {
            mp[i] += 1;
        }
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(auto i:mp)
        {
            pq.push(i.second);
        }
        int rem=0;
        while(!pq.empty())
        {
            rem += pq.top();
            
            if(rem > k)
            {
                return pq.size();
            }
            pq.pop();
        }
        return 0;
    }
};
