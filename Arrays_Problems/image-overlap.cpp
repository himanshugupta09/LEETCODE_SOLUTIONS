class Solution {
public:
    
    int checkers(vector<int> &v1,vector<int> &v2,int x,int y)
    {
        array<int,4> l = {};
        
        int n = v1.size();
        
        for(int i=0;i<n-x;i++)
        {
            l[0] += __builtin_popcount((v1[i]>>y)&v2[i+x]);
            l[1] += __builtin_popcount(v1[i] & (v2[i+x]>>y));
            l[2] += __builtin_popcount((v1[i+x]>>y)&v2[i]);
            l[3] += __builtin_popcount(v1[i+x] & (v2[i]>>y));
        }
        
        
        return *max_element(l.begin(),l.end());
        
    }
    
    
    
    
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
       
        int n1 = img1.size();
        
        vector<int> v1(n1,0),v2(n1,0);
        
        for (int i=0; i<n1; ++i) 
        {
            for (int j=0; j<n1; ++j) 
            {
                if (img1[i][j]) v1[i]|=1<<j;
                if (img2[i][j]) v2[i]|=1<<j;
            }
        }
        
        int res=0;
        
        for (int i=0; i<n1; ++i) 
        {
            for (int j=0; j<n1; ++j) 
			{
                res=max(res,checkers(v1,v2,i,j)); 
                
            }
        }    
	return res;
        
        
    }
};
