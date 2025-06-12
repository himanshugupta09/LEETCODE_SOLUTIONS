class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++)
        {
            int d = arr[i] == x ? INT_MAX : abs(arr[i]-x);
            pq.push({-d,i});
        }
        vector<int>res;
        while(k--)
        {
            pair<int,int>pr = pq.top();
            pq.pop();
            res.push_back(arr[pr.second]);
        }
        return res;
        
    }
};
