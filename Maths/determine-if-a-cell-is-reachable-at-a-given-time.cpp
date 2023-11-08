class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int x = abs(fx-sx);
        int y = abs(sy-fy);
        
        if((x == 0 && y == 0)&&(t == 1))
            return false;
        
        
        return 1 ? (max(x,y)<=t) : 0;
    }
};
