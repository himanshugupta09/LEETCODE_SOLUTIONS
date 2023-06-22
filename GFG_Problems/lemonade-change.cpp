//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        
        int fv = 0,tn = 0;
        
        for(int i=0;i<N;i++)
        {
            if(bills[i] == 20)
            {
                if(tn && fv)
                {
                    tn--;
                    fv--;
                    
                }
                else if(fv >= 3)
                {
                    fv -= 3;
                }
                else
                {
                    return false;
                }
            }
            else if(bills[i] == 10)
            {
                tn++;
                if(fv)
                {
                    fv--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                fv++;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
