class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<bool>visited(n+1,false);

        for(auto i:edges)
        {
            int idx = i[1];
            visited[idx] = true;
        }
        vector<int>res;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
