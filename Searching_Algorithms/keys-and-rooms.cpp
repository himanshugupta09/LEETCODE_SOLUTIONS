class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);

        queue<int>q;
        q.push(0);

        
        visited[0] = true;

        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int rm = q.front();
                q.pop();
                visited[rm] = true;

                for(int el:rooms[rm])
                {
                    if(!visited[el])
                    {
                        q.push(el);
                    }
                }
            }
            
        }

        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};
