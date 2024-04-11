class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            while(k && !s.empty() && (num[i] < s.top()))
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        
        while(k && !s.empty())
        {
            s.pop();
            k--;
        }
        string res;
        
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        
        while(!res.empty() && res[0] == '0')
        {
            res.erase(0,1);
        }
        if(res.empty())
        {
            return "0";
        }
        return res;
    }
};
