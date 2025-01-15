//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int maxL = 0;
        unordered_map<int,int>sum_arr;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum == k)
            {
                maxL = max(maxL,i+1);
            }
            int remaining = sum-k;
            if(sum_arr.find(remaining) != sum_arr.end())
            {
                int length = (i-sum_arr[remaining]);
                maxL = max(maxL,length);
            }
            if(sum_arr.find(sum) == sum_arr.end())
            {
                sum_arr[sum]=i;
            }
        }
        return maxL;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
