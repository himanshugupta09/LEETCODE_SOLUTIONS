//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n = mat.size();
    vector<vector<int>>res(n,vector<int>(n,0));
    
    int i=0,j=0;
    
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<n;l++)
        {
            res[i][j] = mat[k][l];
            i++;
            if(i > n-1)
            {
                i  = 0;
                j++;
            }
        }
    }
    int l = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            mat[i][l] = res[i][j];
            l = (l+1)%n;
        }
    }
    
}


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
