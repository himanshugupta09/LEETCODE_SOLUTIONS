//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        
        map<pair<int,int>,int>mp;
        
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                int sm = A[i] + A[j];
                mp[{i,j}] = sm;
            }
        }
        
        vector<int>res;
        
        for(auto i:mp)
        {
            for(auto j:mp)
            {
                if((i.second == j.second) && (i.first.first != j.first.first) && (i.first.second != j.first.second) && (i.first.second != j.first.first))
                {
                    res.push_back(i.first.first);
                    res.push_back(i.first.second);
                    res.push_back(j.first.first);
                    res.push_back(j.first.second);
                    return res;
                    
                }
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        res.push_back(-1);
        res.push_back(-1);
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends
