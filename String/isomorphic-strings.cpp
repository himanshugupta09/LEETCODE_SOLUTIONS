class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int as[128] = {0}, ta[128] = {0};

        for(int i=0;i<s.size();i++)
        {
            if(as[s[i]] != ta[t[i]]){
                return false;
            }
            else if(!as[s[i]])
            {
                as[s[i]] = i+1;
                ta[t[i]] = i+1;
            }
        }

        return true;
    }
};
