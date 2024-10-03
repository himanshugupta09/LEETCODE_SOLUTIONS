//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n = nums.size();
        int maj = n/3;
        int cnt1 = 0,cnt2 = 0;
        int ele1 = -1,ele2 = -1;
        
        for(int i=0;i<n;i++)
        {
            if(cnt1 == 0 && ele1 != nums[i])
            {
                cnt1++;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && ele2 != nums[i])
            {
                cnt2++;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1)
            {
                cnt1++;
            }
            else if(nums[i] == ele2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(ele1 == nums[i]) a++;
            else if(ele2 == nums[i]) b++;
        }
        if(a > maj && b > maj){
            if(ele1 > ele2) return {ele2,ele1};
            return {ele1,ele2};
        } 
        if(a > maj) return {ele1};
        if(b > maj) return {ele2};
        return {-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
