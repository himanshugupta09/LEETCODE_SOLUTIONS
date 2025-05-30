//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int maxL = 0;
        int n = arr.size();
        unordered_map<int,int>mp;
        int preSum = 0;
        for(int i=0;i<n;i++)
        {
            preSum += (arr[i] == 0) ? -1 : 1;
            if(preSum == 0)
            {
                maxL = i+1;
            }
            if(mp.find(preSum) != mp.end())
            {
                maxL = max(maxL,i-mp[preSum]);
            }
            else
            {
                mp[preSum] = i;
            }
            
        }
        return maxL;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends
