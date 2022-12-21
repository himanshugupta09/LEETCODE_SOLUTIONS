class Solution {
public:

/*
Create an adjacency list where adj[X] contains all the neighbors of node X.
Initialize an array color, storing the color assigned to each node. Initialize it to -1 for all nodes to indicate no colors have been assigned yet.
Run a loop over all the nodes and check if there is any node i which is uncolored.
If a node i has not been colored (color[i] = -1), start a BFS traversal which will cover all the nodes present in the same component as node i.
Initialize a queue with i in the queue.
Assign a color to the source node i, let's say RED = 0.
Then, while the queue is not empty:
Dequeue the first node from the queue.
Iterate over all the neighbors of node and check if any neighbor has the same color as node. If any neighbor matches, then we have a conflict, so return false.
If a color is not yet assigned to the neighbor, assign the opposite color to it. Then, put the neighbor onto the queue.
If any BFS traversal has a conflict, we return false as the answer. Otherwise, we return true if we get through every node without conflict.

*/

    bool BFS(int st,vector<vector<int>>& adj,vector<int>& color)
    {
        queue<int>q;
        q.push(st);
        color[st] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto& next:adj[node])
            {
                if(color[next] == color[node])
                {
                    return false;
                }
                if(color[next] == -1)
                {
                    color[next] = 1-color[node];
                    q.push(next);


                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        
        vector<vector<int>>next(n+1);

        for(auto& dis:dislikes)
        {
            next[dis[0]].push_back(dis[1]);
            next[dis[1]].push_back(dis[0]);
        }

        vector<int>color(n+1,-1);

        for(int i=1;i<=n;i++)
        {
            if(color[i] == -1)
            {
                if(!BFS(i,next,color))
                {
                    return false;
                }
            }
        }

        return true;


        
    }
};
