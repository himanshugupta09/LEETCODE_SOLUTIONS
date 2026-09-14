class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int xa1 = rec1[0],ya1 = rec1[1],xa2=rec1[2],ya2 = rec1[3];
        int xb1 = rec2[0],yb1 = rec2[1],xb2=rec2[2],yb2 = rec2[3];
        
        int width = min(xa2, xb2) - max(xa1, xb1);
        int height = min(ya2, yb2) - max(ya1, yb1);

        if(width > 0 && height > 0){
            return true;
        }
        return false;
    }
};