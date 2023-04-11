//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int mini=max(a,max(b,c));
        if(mini==a){
            if(a<=2*(b+c+1)){
                return a+b+c;
            }
        }
        else if(mini==b){
            if(b<=2*(a+c+1)){
                return a+b+c;
            }
        }
        else if(mini==c){
            if(c<=2*(a+b+1)){
                return a+b+c;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
