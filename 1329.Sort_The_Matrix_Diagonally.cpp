class Solution {
public:
    
    
    void countSort(vector<vector<int>>&mat,int r,int c)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        int i = r;
        int j = c;
        
        vector<int>v(101);
        
        while(i<n && j<m)
        {
            v[mat[i][j]]++;
            i++;
            j++;
            
        }
        
        i = r;
        j = c;
        
        for(int k=0;k<v.size();k++)
        {
            while(v[k]>0)
            {
                mat[i][j] = k;
                v[k]--;
                
                
                i++;
                j++;
                
            }
        }
    }
    
    
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m= mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            countSort(mat,i,0);
        }
        
        for(int j=0;j<m;j++)
        {
            countSort(mat,0,j);
        }
        
        return mat;
        
        
        
}
};
