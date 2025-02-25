//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        stack<int> st;
        st.push(0);
        int ans = 0;
        for(int i = 1; i < n; i++){
            while(st.empty() == false && arr[i] < arr[st.top()]){
                int currElement = arr[st.top()];
                st.pop();
                int nextSmaller = i;
                int prevSmaller = st.empty() == true ? -1 : st.top();
                ans = max(ans, currElement * (nextSmaller - prevSmaller - 1));
            }
            st.push(i);
        }
        while(st.empty() == false){
            int currElement = arr[st.top()];
            st.pop();
            int prevSmaller = st.empty() ? -1 : st.top();
            ans = max(ans, currElement * (n - prevSmaller - 1));
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
