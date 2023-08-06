//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string>res;
    void getPermutations(string S,string &temp,vector<bool> &taken)
    {
        if(temp.size() == S.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<S.size();i++)
        {
            if(!taken[i])
            {
                taken[i] = 1;
                temp += S[i];
                getPermutations(S,temp,taken);
                temp = temp.substr(0,temp.length()-1);
                taken[i] = 0;
            }
        }
        
        
    }
    
    
    vector<string> permutation(string S)
    {
        //Your code here
        if(S.size() <= 1)
        {
            return {S};
        }
        string temp = "";        
        vector<bool>taken(S.size(),0);

        getPermutations(S,temp,taken);
        sort(res.begin(),res.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
