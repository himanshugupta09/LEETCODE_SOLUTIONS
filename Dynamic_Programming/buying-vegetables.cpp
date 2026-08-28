class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i=1;i<n;i++)
        {
           mat[i][0] += min(mat[i-1][1],mat[i-1][2]); 
           mat[i][1] += min(mat[i-1][0],mat[i-1][2]); 
           mat[i][2] += min(mat[i-1][1],mat[i-1][0]); 
        }
        return *min_element(mat[n-1].begin(),mat[n-1].end());
    }
};