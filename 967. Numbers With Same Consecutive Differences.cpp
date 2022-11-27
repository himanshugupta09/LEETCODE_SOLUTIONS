class Solution {
public:
    
void dfs(int n,int k,int val,vector<int> &res)
{
    
    if(n == 0)
    {
        res.push_back(val);
        return;
    }
    
    if(val%10+k >= 0 && val%10+k < 10){
        int tmp = val*10+(val%10+k);
        dfs(n-1,k,tmp,res);
    }
	
	
    if(k != 0 && (val%10-k >= 0 && val%10-k < 10)){
        int tmp = val*10+(val%10-k);
        dfs(n-1,k,tmp,res);
    }
    
  
   
    
        
}    
        
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
     
        vector<int>res;
        
        
       
        
        if(n == 1)
        {
           res = {0,1,2,3,4,5,6,7,8,9};
            return res;
            
        }
        
        for(int i=0;i<9;i++)
        {
            dfs(n-1,k,i+1,res);
            
        }
        
        return res;
        
    
        
        
        
        
        
        
    }
};
