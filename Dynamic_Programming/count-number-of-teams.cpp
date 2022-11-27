class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size();
        
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);
        
        
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            //int cnt = 0;
            for(int j=i+1;j<n;j++)
            {
                if(rating[i] < rating[j])
                {
                    dp1[i]++;
                    
                }
                else if(rating[i]>rating[j])
                {
                    dp2[i]++;
                }
            }
            
            
        }
        
        for(int i=0;i<n;i++)
        {
            //int cnt = 0;
            for(int j=i+1;j<n;j++)
            {
                if(rating[i] < rating[j])
                {
                    cnt += dp1[j];
                    
                    
                }
                else if(rating[i] > rating[j])
                {
                    cnt += dp2[j];
                    
                }
            }
            
            
        }
        
        return cnt;
        
        
        
        
    }
};
