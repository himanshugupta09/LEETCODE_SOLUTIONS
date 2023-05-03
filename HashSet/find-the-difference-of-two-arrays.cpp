class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>l1;
        vector<int>l2;
        
        set<int>sl1(nums1.begin(),nums1.end());
        set<int>sl2(nums2.begin(),nums2.end());

        for(auto i:sl1)
        {
            if(sl2.find(i) == sl2.end())
            {
                l1.push_back(i);
            }
        }

        for(auto i:sl2)
        {
            if(sl1.find(i) == sl1.end())
            {
                l2.push_back(i);
            }
        }

        vector<vector<int>>res;

        res.push_back(l1);
        res.push_back(l2);

        return res;

    }
};
