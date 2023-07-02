class Solution {
public:

    int res = 0;

    void solve(vector<vector<int>>& req,vector<int>& indegree,int n,int idx,int cnt)
    {
        if(idx == req.size())
        {
            for(int i=0;i<n;i++)
            {
                if(indegree[i])
                {
                    return;
                }
            }
            res = max(res,cnt);
            return;
        }
        

        indegree[req[idx][0]]--;
        indegree[req[idx][1]]++;

        solve(req,indegree,n,idx+1,cnt+1);

        indegree[req[idx][0]]++;
        indegree[req[idx][1]]--;

        solve(req,indegree,n,idx+1,cnt);

    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        

        vector<int>inDegree(n,0);
        solve(requests,inDegree,n,0,0);
        return res;
    }
};
