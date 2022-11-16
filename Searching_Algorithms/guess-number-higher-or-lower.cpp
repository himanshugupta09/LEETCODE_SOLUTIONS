class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while(low<=high){
            int m1 = low+(high-low)/3;
            int m2 = high-(high-low)/3;
            int r1 = guess(m1);
            int r2 = guess(m2);
            if(r1 == 0)
                return m1;
            if(r2 == 0)
                return m2;
            else if(r1<0)
                high = m1-1;
            else if(r2>0)
                low = m2+1;
            else{
                low = m1+1;
                high = m2-1;
            }
            
        }
        return -1;
        
    }
};
