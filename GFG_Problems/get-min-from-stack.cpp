//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<pair<int,int> > st;
    int curr_mini ;
  public:
    Solution() {
        curr_mini = INT_MAX; 
    }

    // Add an element to the top of Stack
    void push(int x) {
        curr_mini = min(curr_mini,x);
        st.push({x,curr_mini});
    }

    // Remove the top element from the Stack
    void pop() {
        if(!st.empty()){
            if(curr_mini != st.top().second){
                st.pop();
            } else {
                st.pop();
                if(!st.empty()){
                    curr_mini = st.top().second;
                } else {
                    curr_mini = INT_MAX;
                }
            }
        }
    }

    // Returns top element of the Stack
    int peek() {
        return (!st.empty()) ? st.top().first : -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        return (!st.empty()) ? st.top().second : -1;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
