class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int a = 0;
        int b = n-1;
        
        while(a < b)
        {
            if(mat[a][b] == 1)
            {
                a++;
            }
            else
            {
                b--;
            }
        }
        int cand = a;
        for(int i = 0; i < n; i++)
        {
            if(i == cand) continue;

            // cand knows someone OR someone doesn't know cand
            if(mat[cand][i] == 1 || mat[i][cand] == 0)
                return -1;
        }

        return cand;
    }
};