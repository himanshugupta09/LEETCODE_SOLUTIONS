//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isSafe(vector<vector<int>>&mat,int n,int m,int num)
    {
        for(int i=0;i<9;i++)
        {
            if(mat[n][i] == num)
            {
                return false;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(mat[i][m]  == num)
            {
                return false;
            }
        }
        int stat = n-(n%3),statc = m-(m%3);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(mat[i+stat][j+statc] == num)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<int>>&mat,int i,int j)
    {
        int n = mat.size();
        //int m = mat[0].size();
        if(i == n-1 && j == n)
        {
            return true;
        }
        if(j == n)
        {
            j = 0;
            i++;
        }
        if(mat[i][j] != 0)
        {
            return solve(mat,i,j+1);
        }
        for (int num = 1; num <= n; num++) {

        // If it is safe to place num at current position
        if (isSafe(mat, i, j, num)) {
            mat[i][j] = num;
            if (solve(mat, i, j + 1))
                return true;
            mat[i][j] = 0;
        }
    }
  
      return false;
        
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat,0,0);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
