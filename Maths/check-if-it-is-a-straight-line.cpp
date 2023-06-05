class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dy = coordinates[1][1]-coordinates[0][1];
        int dx = coordinates[1][0]-coordinates[0][0];
        for(int i = 2; i<coordinates.size(); ++i) if((coordinates[i][1]-coordinates[0][1])*dx != (coordinates[i][0]-coordinates[0][0])*dy) return false;
        return true;
        
    }
};
