//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    char last = '#';
    int acn=0,bcn = 0;
    for(int i=0;i<str.size();i++)
    {
        char cur = str[i];
        if(last == cur)
        {
            continue;
        }
        if(str[i] == 'a')
        {
            acn++;
        }
        else
        {
            bcn++;
        }
        last = str[i];
        
    }
    return min(acn,bcn)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends
