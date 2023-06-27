class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap;
        vector<vector<int>>res;

        set<pair<int,int>>vis;

        int n = nums1.size();
        int m = nums2.size();

        //int i,j;

        minHeap.push({nums1[0] + nums2[0],{0,0}});
        vis.insert({0,0});

        while(k-- && !minHeap.empty())
        {
            auto tp = minHeap.top();
            minHeap.pop();

            int i = tp.second.first;
            int j = tp.second.second;

            res.push_back({nums1[i],nums2[j]});

            if(i+1 < n && vis.find({i+1,j}) == vis.end())
            {
                minHeap.push({nums1[i+1]+nums2[j],{i+1,j}});
                vis.insert({i+1,j});
            }

            if(j+1 < m && vis.find({i,j+1}) == vis.end())
            {
                minHeap.push({nums1[i]+nums2[j+1],{i,j+1}});
                vis.insert({i,j+1});
            }

        }

        return res;



    }
};
