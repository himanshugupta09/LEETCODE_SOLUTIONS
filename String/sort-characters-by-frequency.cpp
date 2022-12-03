class Solution {
public:
     
    string frequencySort(string s) {

        unordered_map<char,int>mp;
        vector<string>has(s.size()+1,"");

        set<char>st(s.begin(),s.end());

        if(st.size() == 1)
        {
            return s;
        }

        string res;

        for(char i:s){
            mp[i]++;
        }
        for(auto& it:mp)
        {
            int n = it.second;
            char c = it.first;

            has[n].append(n,c);

        }


        for(int i=s.size()-1;i>0;i--)
        {
            if(!has[i].empty())
            {
                res.append(has[i]);
            }

        }

        return res;






    }
};
