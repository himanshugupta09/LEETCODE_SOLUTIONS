class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>maxHeap;

        for(auto i:nums)
        {
            maxHeap.push(i);
        }
        int res = 0;
        while(k--)
        {
            res = maxHeap.top();
            maxHeap.pop();
        }
        return res;
    }
};
