class Solution {
public:
    
    /* Algorithm to be followed to solve out problem 
    
    1. Sort the tokens, l = 0 and r = length - 1
    2. If there is enough power to flip the token[l], then do it and get 1 point.
    3. if there is not enough power to flip token[l], then use 1 point to get the token[r]             power.
     4. If can not do both, stop.
    
    
    
    */
    
    
    
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
     
        sort(tokens.begin(),tokens.end());
        
        int res = 0;
        int score = 0;
        
        int low = 0,high = tokens.size()-1;
        
        while(low <= high && (power >= tokens[low] || res > 0))
        {
           
            while(low <= high && power >= tokens[low])
            {
                power -= tokens[low++];
                score++;
                
            }
            
            res = max(res,score);
            
            if(low <= high && score > 0)
            {
                power += tokens[high--];
                score--;
                
                
            }
            
            
        }
        
        return res;
        
        
    }
};



/* 
    Time Complexity : O(NlogN)
    Space Complexity : O(N)
    
    */
