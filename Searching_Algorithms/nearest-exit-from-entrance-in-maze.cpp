class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();
        int m = maze[0].size();

        vector<pair<int,int>>dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int strt = entrance[0];
        int strcl = entrance[1];
        maze[strt][strcl] = '+';
        queue<array<int,3>>q;

        q.push({strt,strcl,0});

        while(!q.empty())
        {
            auto[cur_row,cur_col,cur_dis] = q.front();
            q.pop();


            for(auto dis:dirs)
            {
                int nextR = cur_row + dis.first,nextC = cur_col + dis.second;

                if(0 <= nextR && nextR < n && 0 <= nextC && nextC<m && maze[nextR][nextC] == '.')
                {
                    if(nextR == 0 || nextR == n-1 || nextC == 0 || nextC == m-1)
                    {
                        return cur_dis+1;
                    }

                    maze[nextR][nextC] = '+';
                    q.push({nextR, nextC, cur_dis + 1});

                }
            }
        }

        return -1;


    }
};
