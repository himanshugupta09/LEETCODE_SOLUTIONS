class Solution {
public:
    vector<int>orig;
    Solution(vector<int>& nums) {
        orig = nums;
    }
    
    vector<int> reset() {
        return orig;
    }
    
    vector<int> shuffle() {
        vector<int>temp = orig;
        vector<int>shuffled;

        while(temp.size() > 0)
        {
            int idx = rand()%temp.size();
            shuffled.push_back(temp[idx]);
            temp[idx] = temp.back();
            temp.pop_back();
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
