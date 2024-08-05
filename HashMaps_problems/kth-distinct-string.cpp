class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string res;
        
        int kth = 0;
        map<string,int>mp;
        for(auto i:arr)
        {
            mp[i]++;
        }
        for(auto i:arr)
        {
            if(mp[i] == 1 && kth < k)
            {
                kth++;
                if(kth == k)
                {
                    return i;
                }
            }
            
        }
        return res;
    }
};
