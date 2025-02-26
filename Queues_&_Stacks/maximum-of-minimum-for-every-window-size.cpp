//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        stack<int>st;
          stack<int>st2;
          int n=arr.size();
          vector<int>left(n,-1);
          vector<int>right(n,n);
          for(int i=0;i<n;i++)
          {
              while(!st.empty() && arr[i]<=arr[st.top()])
              {
                  st.pop();
              }
              if(st.empty())
              {
                  left[i]=-1;
              }
              else{
                  left[i]=st.top();
              }
              st.push(i);
          }
          for(int i=n-1;i>=0;i--)
          {
              while(!st2.empty() && arr[i]<=arr[st2.top()])
              {
                  st2.pop();
              }
              if(st2.empty())
              {
                  right[i]=n;
              }
              else{
                  right[i]=st2.top();
              }
              st2.push(i);
          }
          
          vector<int>ans(n,0);
          for(int i=0;i<n;i++)
          {
              int mx=right[i]-left[i]-1;
              ans[mx-1]=max(ans[mx-1],arr[i]);
          }
          for(int i=n-2;i>=0;i--)
          {
              ans[i]=max(ans[i],ans[i+1]);
          }
          return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
