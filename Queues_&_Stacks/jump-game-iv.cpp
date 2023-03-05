class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 0 || n == 1)
        {
            return 0;
        }

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
            
        }
        
        queue<int>indices;
        indices.push(0);
        vector<bool>vis(n);
        vis[0] = true;

        int moves = 0;

        while(!indices.empty())
        {
            int sz = indices.size();
            while(sz--)
            {
                int curi = indices.front();
                indices.pop();

                if(curi == n-1)
                {
                    return moves;
                }

                vector<int>& jnp = mp[arr[curi]];
                jnp.push_back(curi-1);
                jnp.push_back(curi+1);

                for(auto jnpx:jnp)
                {
                    if(jnpx >= 0 && jnpx < n && !vis[jnpx])
                    {
                        indices.push(jnpx);
                        vis[jnpx] = true;

                    }
                }
                jnp.clear();

            }
            moves++;
        }
        return -1;

         
    }
};
