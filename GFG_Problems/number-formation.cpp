//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {

  public:
    int ans = 0 , mod = 1e9+7;
  vector<vector<vector<int>>>dpcnt , dpsol ;
  long long countt(int x , int y , int z)
  {
      if(x == 0 && y == 0 && z == 0 ) return 1 ;
      if(x<0 || y<0 || z<0) return 0 ;
      
      if(dpcnt[x][y][z] != -1) return dpcnt[x][y][z] ;
      
      long long res = 0 ;
      
      res = ((countt(x-1 , y , z)%mod) + (countt(x , y-1 , z)%mod) + (countt(x , y , z-1)%mod))%mod ;
      
      return dpcnt[x][y][z] = res%mod ;
  }
  
  
  long long solve(int x , int y , int z )
  {
      
      if(x == 0 && y == 0 && z == 0 ) return 0 ;
      if(x<0 || y<0 || z<0) return 0 ;
      
      if(dpsol[x][y][z] != -1) return dpsol[x][y][z] ;
      
      long long res = 0 ;
      
      res+=((((solve(x-1,y,z)%mod)*10)%mod + countt(x-1,y,z)*4)%mod)%mod ;
	  res+=((((solve(x,y-1,z)%mod)*10)%mod + countt(x,y-1,z)*5)%mod)%mod ;
	  res+=((((solve(x,y,z-1)%mod)*10)%mod + countt(x,y,z-1)*6 )%mod)%mod;
	
	  dpsol[x][y][z]=res%mod;
	  ans += (res)%mod ;
	  ans = ans%mod ;
	  return res ;
      
  }
  
    int getSum(int x, int y, int z) 
    {
    
      dpcnt.resize(x+1 , vector<vector<int>>(y+1 , vector<int>(z+1 , -1))) ;
      dpsol.resize(x+1 , vector<vector<int>>(y+1 , vector<int>(z+1 , -1))) ;
        
       solve(x,y,z) ;
      
      return ans%mod ;  
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends
