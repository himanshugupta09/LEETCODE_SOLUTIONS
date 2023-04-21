//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    struct Node{
        Node *nodes[26];
    };
    
    void insert(Node* node,string s)
    {
        Node* root = node;
        for(auto& c:s)
        {
            if(root->nodes[c-'a'] == NULL)
            {
                root->nodes[c-'a'] = new Node();
                
            }
            root = root->nodes[c-'a'];
        }
    }
    
    bool search(Node* node,string s)
    {
        Node* root = node;
        for(auto& c:s)
        {
            if(root->nodes[c-'a'] == NULL)
            {
                return false;
                
            }
            root = root->nodes[c-'a'];
        }
        return true;
    }
    
    
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        Node* root = new Node();
        
        for(auto& s:s1)
        {
            insert(root,s);
            reverse(s.begin(),s.end());
            insert(root,s);
            
        }
        int res = 0;
        for(auto&s:s2)
        {
            string r = s;
            reverse(r.begin(),r.end());
            
            if(search(root,s) || search(root,r))
            {
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
