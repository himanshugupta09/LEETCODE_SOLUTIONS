class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int>maxHeap;
        int mini = INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2 == 1)
            {
                nums[i] = nums[i]*2;
            }
            mini = min(mini,nums[i]);
            maxHeap.push(nums[i]);
        }

        int mnDev = INT_MAX;
        while(true)
        {
            int maxVal = maxHeap.top();
            maxHeap.pop();
            mnDev = min(mnDev, maxVal - mini);
            
            if (maxVal % 2 == 1)
                break;
            maxVal = maxVal / 2;
            mini = min(mini, maxVal);
            maxHeap.push(maxVal);


        }

        return mnDev;


        

        
    }
};
