class Solution {
public:
    int longestString(int x, int y, int z) {
        if(y > x)
        {
            swap(x,y);
        }
        if(x == y)
        {
            return x*4 + z*2;
        }
        return y*4 + 2 + z*2;
    }
};
