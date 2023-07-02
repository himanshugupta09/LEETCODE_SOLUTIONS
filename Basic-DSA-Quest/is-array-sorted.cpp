#include<bits/stdc++.h>
using namespace std;

// This Approach uses Recursion

// Time Complexity : O(N)
// Space Complexity : O(N) Auxilary Stack Space

int sortArray(vector<int>& A,int n)
{
    if(n == 1)
    {
        return 1;
    }
    return (A[n-1] < A[n-2]) ? 0 : sortArray(A,n-1);
}

int main()
{
    int n;
    cin >> n;

    vector<int>A(n);
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }

    cout << "Is Array Sorted  : " << "\n";

    int checker = sortArray(A,n);
    if(checker) cout << "YES\n";
    else cout << "NO\n";
    

    return 0;
}
