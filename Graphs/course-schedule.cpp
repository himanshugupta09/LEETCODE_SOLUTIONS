class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //int n = prerequisites.size();
        vector<int>indeg(numCourses,0);
        vector<vector<int>>adj(numCourses);
        

        for(auto pr:prerequisites)
        {
            adj[pr[1]].push_back(pr[0]);
            indeg[pr[0]]++;
        }


        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }

        int nodeVist = 0;
        while(!q.empty())
        {
            nodeVist++;
            int p = q.front();
            q.pop();

            for(auto neigh:adj[p])
            {
                indeg[neigh]--;
                if(indeg[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }

       return nodeVist == numCourses;




        
    }
};
