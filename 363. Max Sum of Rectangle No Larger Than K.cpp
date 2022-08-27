class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int ans = INT_MIN;
        
        for(int i=0;i<c;i++)
        {
            vector<int>sm(r,0);
            
            for(int j = i;j<c;j++)
            {
                for(int k=0;k<r;k++)
                {
                    sm[k] += matrix[k][j];
                    
                }
                
                set<int>st;
                st.insert(0);
                
                int Csm = 0,Cmax = INT_MIN;
                
                for(int l = 0;l<r;l++)
                {
                    Csm += sm[l];
                    
                    auto it = st.lower_bound(Csm-k);
                    
                    if(it != st.end())
                    {
                        Cmax = max(Cmax,Csm - (*it));
                    }
                    st.insert(Csm);
                    
                    
                }
                ans = max(ans,Cmax);
                
            }
            
        }
        return ans;
        
        
    }
};
