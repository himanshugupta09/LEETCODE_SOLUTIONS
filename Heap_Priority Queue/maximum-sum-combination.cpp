//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        priority_queue<int>pq;
        
        for(int i=N-1;i>=0;i--)
        {
            for(int j=N-1;j>=0;j--)
            {
                int sm = (A[i] + B[j])*-1;
                if(pq.size() < K)
                {
                    pq.push(sm);
                }
                else if(sm < pq.top())
                {
                    pq.pop();
                    pq.push(sm);
                }
                else
                {
                    break;
                }
                
            }
        }
        vector<int>res(K--);
        while(!pq.empty())
        {
          res[K--] = pq.top()*-1;
           pq.pop();
        }
        //reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
