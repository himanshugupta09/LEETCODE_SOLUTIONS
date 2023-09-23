class Solution {
public:
    static bool cmp(string& a,string& b)
    {
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int res = 0;
        unordered_map<string,int>word_map;

        for(string w:words)
        {
           for(int i=0;i<w.length();i++)
           {
               string predecessor = w.substr(0,i) + w.substr(i+1);
               word_map[w] = max(word_map[w],word_map[predecessor]+1);
           }
           res = max(res,word_map[w]);
        }
        return res;

    }
};
