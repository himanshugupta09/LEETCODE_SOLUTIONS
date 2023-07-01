class Solution {
public:

    int dfs(int i,int zc,int k,vector<int>& cookies,vector<int>& dis)
    {
        if(cookies.size()-i < zc)
        {
            return INT_MAX;
        }
        if(i == cookies.size())
        {
            return *max_element(dis.begin(),dis.end());

        }
        else
        {

           int  res = INT_MAX;
            for(int j = 0;j<k;j++)
            {
                zc -= dis[j] == 0 ? 1 : 0;
                dis[j] += cookies[i];
                
                res = min(res,dfs(i+1,zc,k,cookies,dis));

                dis[j] -= cookies[i];
                zc += dis[j] == 0 ? 1 : 0;
            }
            return res;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int>dis(k,0);

        return dfs(0,k,k,cookies,dis);


    }
};
