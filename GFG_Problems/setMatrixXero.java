//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setRowToZero(vector<vector<int>> &mat,int i){
        for(int n=0;n<mat[0].size();n++){
            mat[i][n]=0;
        }
    }
    void setColToZero(vector<vector<int>> &mat,int j){
        for(int n=0;n<mat.size();n++){
            mat[n][j]=0;
        }
    }
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        vector<int> rows,cols;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        for(auto row:rows){
            setRowToZero(mat,row);
        }
        for(auto col:cols){
            setColToZero(mat,col);
        }
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
