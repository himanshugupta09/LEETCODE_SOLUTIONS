class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        unordered_map<int,int>mp;
         for(int i=0;i<nums1.size();i++)
         {
             mp[nums1[i][0]] = nums1[i][1];
         }
         
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i][0]] += nums2[i][1];
        }
        
        vector<vector<int>>res;
        for(auto i:mp)
        {
            vector<int>temp;
            temp.push_back(i.first);
            temp.push_back(i.second);
            
            res.push_back(temp);
            
        }
        sort(res.begin(),res.end());
        return res;
    }
};