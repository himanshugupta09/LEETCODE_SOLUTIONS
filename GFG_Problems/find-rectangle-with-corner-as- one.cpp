class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
         int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    for(int k=i+1;k<n;k++){
                        for(int l=j+1;l<m;l++){
                            if(mat[k][l]==1 and mat[i][l]==1 and mat[k][j]==1)
                                return true;
                        }
                    }
                }
            }
        }
        return false;
        
    }
};
