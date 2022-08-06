/* ====================================================================================================================================================================
                                                     IT IS MATHEMATICAL IN WHICH WE CALCULATED THE ANSWER AS 
                                                     
                                                     ANS = LOG(BUCKETS)/LOG(MINUTESTODIE)
======================================================================================================================================================================
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = 0,tot = 1;
        int L = (minutesToTest/minutesToDie) + 1;
        while(tot<buckets)
        {
            tot *= L;
            ans++;
            
        }
        return ans;
        
    }
};

/* ======================================================================================================================================================================
                                                       SAME APPROACH WITH THE INBULT FUNCTIONS
=========================================================================================================================================================================
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        return ceil((log(buckets))/log(minutesToTest/minutesToDie+1));
        
    }
};
