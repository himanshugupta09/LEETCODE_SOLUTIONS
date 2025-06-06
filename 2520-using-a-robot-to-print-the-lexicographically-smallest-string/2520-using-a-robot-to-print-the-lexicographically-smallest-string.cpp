class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char,int>mpp;
        for(char c:s)
        {
            mpp[c]++;
        }
        stack<char>stk;
        char mini = 'a';
        string res;
        for(auto c:s)
        {
            stk.emplace(c);
            mpp[c]--;
            while(mini != 'z' && mpp[mini] == 0)
            {
                mini++;
            }
            while(!stk.empty() && stk.top() <= mini)
            {
                res.push_back(stk.top());
                stk.pop();
            }
        }
        return res;
        
    }
};