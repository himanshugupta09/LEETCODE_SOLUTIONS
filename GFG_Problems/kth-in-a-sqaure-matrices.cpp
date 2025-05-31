class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(auto row:matrix)
        {
            for(auto col:row)
            {
                minHeap.push(col);
                
            }
        }
        int res = -1;
        while(k > 0)
        {
            res = minHeap.top();
            minHeap.pop();
            k--;
        }
        return res;
    }
};
