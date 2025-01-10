//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int>distinctCounts;
        int n = arr.size();
        unordered_map<int,int>uniques;
        
        for(int i=0;i<k;i++)
        {
            uniques[arr[i]]++;
        }
        distinctCounts.push_back(uniques.size());
        int right = k-1;
        for(int right=k;right<n;right++)
        {
            
            uniques[arr[right]]++;
            uniques[arr[right-k]]--;
            if(uniques[arr[right-k]]  == 0) uniques.erase(arr[right-k]);
            distinctCounts.push_back(uniques.size());
            
        }
        return distinctCounts;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
