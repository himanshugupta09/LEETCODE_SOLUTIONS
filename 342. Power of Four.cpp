class Solution {
public:
    
    float logn(int n,int r)
    {
        return log(n)/log(r);
    }
    
    
    bool isPowerOfFour(int n) {
        
        if(n == 0)
        {
            return false;
        }
        else{
            return floor(logn(n,4)) == ceil(logn(n,4));
        }
    }
};
