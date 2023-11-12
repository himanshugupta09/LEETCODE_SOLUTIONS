//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int num1=str1.size(),i,j=2;
        if(num1 != str2.size()) return false;
        else {
            for(i=0;i<num1;++i){
                if((str1[j]!=str2[i]) && (str2[j]!=str1[i])) return false;
                j=(j+1)%num1;
            }
        }return true;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends
