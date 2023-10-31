class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        
        if(n == 1){
            return pref;
        }
        
        for(int i=n-1;i>=1;i--)
        {
            pref[i] = pref[i]^pref[i-1];
        }
        return pref;
        
    }
};
