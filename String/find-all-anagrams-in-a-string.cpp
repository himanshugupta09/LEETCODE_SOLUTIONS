class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>indexRes;

        vector<int>p_hash(26,0);
        vector<int>s_hash(26,0);

        int i=0;
        int j=0;

        int n = s.size();
        int m = p.size();

        if(n < m)
        {
            return indexRes;
        }

        while(j < m)
        {
            s_hash[s[j]-'a']++;
            p_hash[p[j] - 'a']++;
            j++;
        }
        j--;

        while(j < n)
        {
            if(p_hash == s_hash)
            {
                indexRes.push_back(i);
            }
            j++;
            
            if(j != n)
            {
                s_hash[s[j]-'a']++;

            }
            s_hash[s[i]-'a']--;
            i++;
        }

        return indexRes;



    }
};
