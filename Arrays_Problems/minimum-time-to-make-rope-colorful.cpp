class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
     
        
        int totTime = 0,curMaxTime = 0;
        
        for(int i=0;i<colors.size();i++)
        {
            if(i > 0 && colors[i] != colors[i-1])
            {
                curMaxTime =  0;
            }
            
            
            
            totTime += min(curMaxTime,neededTime[i]);
            curMaxTime = max(curMaxTime,neededTime[i]);
            
            
            
        }
        
        
        return totTime;
        
        
        
    }
};
