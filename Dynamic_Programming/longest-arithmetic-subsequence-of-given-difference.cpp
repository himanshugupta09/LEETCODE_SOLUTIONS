class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        
        unordered_map<int,int>mp;


        for(auto i:arr)
        {
            mp[i] = mp[i-difference]+1;
        }
        int res = 1;
        for(auto i:mp)
        {
            res = max(res,i.second);
        }
        return res;

    }
};
