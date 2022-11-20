//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    
    bool isPrime(int x)
    {
        if (x <= 1)
          return false;
        
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
 
    return true;
    }
    
    string isSumOfTwo(int N){
        // code here
        
        if(N%2 == 0 && N > 2)
        {
            return "Yes";
        }
        if(isPrime(N-2))
        {
            return "Yes";
        }
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
