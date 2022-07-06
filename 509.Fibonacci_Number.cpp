class Solution {
public:
    int fib(int n) {
        int f=0,s = 1;
        if(n==0){
            return n;
        }
        else{
            int nt =  0;
            for(int i=2;i<=n;i++)
            {
                nt = f+s;
                f = s;
                s = nt;
                
            }
            return s;
        }
    }
};

/* this is the most simplest and faster approach  
only the requirement for this appraoch is that the usse of loops 
In case very large inputs this solution may not be the best one 
*/
