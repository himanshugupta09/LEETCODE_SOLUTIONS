class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(auto str:knowledge){
            mpp[str[0]] = str[1];
        }
        stack<char>stk;

        string res;
        bool openSeen = false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ')')
            {
                string curr;
                while(!stk.empty())
                {
                    curr += stk.top();
                    stk.pop();
                }
                reverse(curr.begin(),curr.end());
                if(mpp.find(curr) == mpp.end())
                {
                    res += '?';
                }
                else
                {
                    res += mpp[curr];
                }
                openSeen = false;
            }
            else if(s[i] != '(' && !openSeen){
                res += s[i];
            }
            else 
            {
                openSeen = true;
                if(s[i] != '('){
                    stk.push(s[i]);
                }
            }
        }
        return res;
    }
};