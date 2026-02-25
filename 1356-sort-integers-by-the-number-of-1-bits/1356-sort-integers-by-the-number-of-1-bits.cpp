class Solution {
public:
    // bool operator()(pair<int,int> a, pair<int,int> b)
    // {
    //     return a.second<b.second;
    // }
    vector<int> sortByBits(vector<int>& arr) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        for(auto i:arr)
        {
            int cnt = __builtin_popcount(i);
            minHeap.push({cnt,i});
        }
        arr.erase(arr.begin(),arr.end());
        
        while(!minHeap.empty())
        {
            int num = minHeap.top().second;
            minHeap.pop();
            arr.push_back(num);
        }
        return arr;
    }
};