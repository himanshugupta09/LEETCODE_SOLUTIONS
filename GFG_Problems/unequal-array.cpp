//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        int sum_a = 0,sum_b = 0;
        int odd_cnt_a = 0,odd_cnt_b = 0;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        vector<int>oddA;
        vector<int>evenA;
        vector<int>oddB;
        vector<int>evenB;
        
        
        for(auto i:A)
        {
            if(i%2)
            {
                odd_cnt_a++;
                oddA.push_back(i);
            }
            else
            {
                evenA.push_back(i);
            }
            sum_a += i;
        }
        for(auto i:B)
        {
            if(i%2)
            {
                odd_cnt_b++;
                oddB.push_back(i);
            }
            else
            {
                evenB.push_back(i);
            }
            sum_b += i;
        }
        long long res = 0;
        
        if(oddA.size() != oddB.size() || evenA.size() != evenB.size() || sum_a != sum_b)
        {
            return -1;
        }
        else
        {
            for(int i=0;i<oddA.size();i++)
            {
                res += abs(oddA[i]-oddB[i]);
            }
            for(int i=0;i<evenA.size();i++)
            {
                res += abs(evenA[i]-evenB[i]);
            }
            res/=4;
            return res;
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
