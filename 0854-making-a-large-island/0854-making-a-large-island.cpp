class Solution {
public:
    int exploreIsland(vector<vector<int>>&grid,int islandID,int curR,int curC)
    {
        if(curR < 0 || curC < 0 || curR >= grid.size() || curC>= grid[0].size() || grid[curR][curC] != 1)
        {
            return 0;
        }
        grid[curR][curC] = islandID;
        return 1 + exploreIsland(grid,islandID,curR+1,curC)+exploreIsland(grid,islandID,curR-1,curC) + exploreIsland(grid,islandID,curR,curC+1) + exploreIsland(grid,islandID,curR,curC-1);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int islandID = 2;
        unordered_map<int,int>islandSizes;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {

                    islandSizes[islandID] = exploreIsland(grid,islandID,i,j);
                    islandID++;
                }
            }
        }
        if(islandSizes.empty())
        {
            return 1;
        }
        if(islandSizes.size() == 1)
        {
            islandID--;
            return (islandSizes[islandID] == grid.size()*grid[0].size() ? islandSizes[islandID] : islandSizes[islandID]+1);
        }
        int maxIslandSize = 1;
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 0) {
                    int currentIslandSize = 1;
                    unordered_set<int> neighboringIslands;

                    // Check down
                    if (currentRow + 1 < grid.size() &&
                        grid[currentRow + 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow + 1][currentColumn]);
                    }

                    // Check up
                    if (currentRow - 1 >= 0 &&
                        grid[currentRow - 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow - 1][currentColumn]);
                    }

                    // Check right
                    if (currentColumn + 1 < grid[0].size() &&
                        grid[currentRow][currentColumn + 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn + 1]);
                    }

                    // Check left
                    if (currentColumn - 1 >= 0 &&
                        grid[currentRow][currentColumn - 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn - 1]);
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands) {
                        currentIslandSize += islandSizes[id];
                    }

                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;

        
    }
};