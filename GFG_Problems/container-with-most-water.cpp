//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left = 0;
        int right = arr.size()-1;
        int maxWater = 0;
        while(left <= right)
        {
            int curWater = min(arr[left],arr[right])*(right-left);
            maxWater = max(maxWater,curWater);
            if(arr[left] < arr[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxWater;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
