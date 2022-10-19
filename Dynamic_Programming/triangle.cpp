class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
       int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++) 
			dp[n-1][i] = triangle[n-1][i];
		for(int i = n-2; i >= 0; i--) {
			for(int j = i; j >= 0; j--) {
				int up = triangle[i][j] + dp[i+1][j];
				int up_left = triangle[i][j] + dp[i+1][j+1];
				dp[i][j] = min(up, up_left);
			}
		}
		return dp[0][0];
        
        
    }
};
