//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        int res = N;
        int id = 0;
        int mx = 0;
        map<char,int>mp;
        for(int i=0;i<N;i++)
        {
            mp[tasks[i]]++;
            mx = max(mx,mp[tasks[i]]);
        }
        id = (mx-1)*K+(mx-1);
        
        for(auto i:mp)
        {
            id -= min(mx-1,i.second);
        }
        return (id>0)?(res+id):res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
