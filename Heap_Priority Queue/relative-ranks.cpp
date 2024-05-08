class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue<pair<int,int>>maxHeap;
        int n = score.size();
        for(int i=0;i<n;i++)
        {
            maxHeap.push({score[i],i});
        }
        vector<string>res(n);
        int done = 1;
        while(!maxHeap.empty())
        {
            pair<int,int>tp = maxHeap.top();
            maxHeap.pop();
            if(done == 1)
            {
                res[tp.second] = "Gold Medal";
            }
            else if(done == 2)
            {
                res[tp.second] = "Silver Medal";
            }
            else if(done == 3)
            {
                res[tp.second] = "Bronze Medal";
            }
            else
            {
                res[tp.second] = to_string(done);
            }
            done++;
        }
        return res;
    }
};
