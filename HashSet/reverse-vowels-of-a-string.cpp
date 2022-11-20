class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j = s.size()-1;

        set<char>st = {'a','e','i','o','u'};

        while(i < j)
        {
            if(st.find(tolower(s[i])) != st.end() && st.find(tolower(s[j])) != st.end())
            {
                swap(s[i],s[j]);

                i++;
                j--;

            }
            else if(st.find(tolower(s[i])) != st.end() && st.find(tolower(s[j])) == st.end())
            {
                j--;

            }
            else if(st.find(tolower(s[i])) == st.end() && st.find(tolower(s[j])) != st.end())
            {
                i++;
                
            }
            else{
                i++;
                j--;
                
            }
        }

        return s;

    }

};
