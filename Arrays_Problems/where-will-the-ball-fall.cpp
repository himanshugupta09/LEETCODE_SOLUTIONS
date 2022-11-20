class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
     
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>res(m,-1);
        
        for(int i=0;i<m;i++)
        {
            int a,b;
            a = 0;
            b = i;
            
            while(true)
            {
                if(a >= n)
                {
                    if(b >= 0 && b < m)
                    {
                        res[i] = b;
                    }
                    break;
                    
                }
                else{
                    if(b+1 < m && grid[a][b] == 1 && grid[a][b+1] == 1)
                    {
                        a++;
                        b++;
                        
                    }
                    else if(b-1 >= 0 && grid[a][b] == -1 && grid[a][b-1] == -1)
                    {
                        a++;
                        b--;
                        
                    }
                    else{
                        break;
                    }
                }
            }
        }
        
        return res;
        
        
        
    }
};


/* 
Time Complexity : O(N^2)
Space Complexity :  O(M)
*/

