class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++)
        {
            if(first[s[i]-'a'] == -1){
                first[s[i]-'a'] = i;
            }
            last[s[i]-'a'] = i;
        }
        vector<pair<int,int>>intervals;
        for(int i=0;i<n;i++)
        {
            int ch = s[i]-'a';
            if(i != first[ch]) continue;

            int l = i;
            int r = last[ch];

            bool valid = true;
            for(int k=l;k<=r;k++)
            {
                int curr_ch = s[k]-'a';
                if(first[curr_ch] < l)
                {
                    valid = false;
                    break;
                }
                r = max(r,last[curr_ch]);
            }
            if(valid)
            {
                intervals.push_back({l,r});
            }
        }
        sort(intervals.begin(), intervals.end(),
            [](auto &a, auto &b) {
                return a.second < b.second;
            });
 
        vector<string>res;
        int prev = -1;
        for(auto [l,r]:intervals)
        {
            if(l > prev)
            {
                res.push_back(s.substr(l,r-l+1));
                prev = r;
            }
        }
        return res;
    }
};