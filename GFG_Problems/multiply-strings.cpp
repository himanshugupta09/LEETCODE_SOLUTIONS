//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        int sign = 1;
        if (s1[0] == '-') sign *= -1, s1 = s1.substr(1);
        if (s2[0] == '-') sign *= -1, s2 = s2.substr(1);

        while (s1.size() > 1 && s1[0] == '0') s1.erase(0, 1);
        while (s2.size() > 1 && s2[0] == '0') s2.erase(0, 1);

        if (s1 == "0" || s2 == "0") return "0";

        int n = s1.size(), m = s2.size();
        vector<int> res(n + m, 0);

        for (int i = n-1; i >= 0; --i)
            for (int j = m-1; j >= 0; --j)
                res[i+j+1] += (s1[i]-'0')*(s2[j]-'0');

        for (int i = n+m-1; i > 0; --i) {
            res[i-1] += res[i]/10;
            res[i] %= 10;
        }

        int idx = (res[0]==0);
        string ans = "";
        for (; idx < n+m; ++idx) ans += (res[idx]+'0');
        if (sign == -1) ans = '-' + ans;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
