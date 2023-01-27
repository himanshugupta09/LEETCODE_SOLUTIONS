class Solution {
public:

    bool isCon(unordered_set<string>& st,string w)
    {
        int ls = w.size();

        for(int i=0;i<ls;i++)
        {
            string pre = w.substr(0,i+1);
            string suf = w.substr(i+1);

            if((st.find(pre) != st.end() && isCon(st,suf)) || (st.find(pre) != st.end() && st.find(suf) != st.end()))
            {
                return true;
            }


        }
        return false;
    }


    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
          int n = words.size();

          unordered_set<string>st(begin(words),end(words));

        vector<string>res;
        
          for(int i=0;i<n;i++)
          {
              string w = words[i];

              if(isCon(st,w))
              {
                  res.push_back(w);
              }
          }

          return res;
    }
};
