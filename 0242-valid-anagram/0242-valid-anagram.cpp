// Approach 1
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         if(n != m)
//         {
//             return false;
//         }
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         return s == t;
//     }
// };

class Solution {
    /* Optimised Approach*/
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m)
        {
            return false;
        }
        unordered_map<char,int>mpp;
        for(auto ch:s)
        {
            mpp[ch]++;
        }
        for(auto i:t)
        {
            if(mpp.find(i) == mpp.end() || mpp[i] == 0)
            {
                return false;
            }
            mpp[i]--;
        }
        return true;
    }
};