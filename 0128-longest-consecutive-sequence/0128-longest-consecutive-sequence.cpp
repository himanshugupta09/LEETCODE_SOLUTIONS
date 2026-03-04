class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>stt(nums.begin(),nums.end());
        int maxLen = 0;
        
        for(int num:stt)
        {
            int curLen = 0;
            int curN = num;
            if(stt.find(num-1) == stt.end())
            {
                while(stt.find(curN) != stt.end())
                {
                    curN++;
                    curLen++;
                }
                maxLen = max(maxLen,curLen);
            }
        }
        return maxLen;
    }
};