//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countS(vector<int>&arr,int pages)
    {
        int n = arr.size(); //size of array.
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                //add pages to current student
                pagesStudent += arr[i];
            }
            else {
                //add pages to next student
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n)
        {
            return -1;
        }
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low <= high)
        {
            int mid = (low+high)/2;
            int s = countS(arr,mid);
            if(s > k)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
            
        }
        return low;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
