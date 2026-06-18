class Solution {
public:
    vector<vector<string>>res;
    bool isPalindrome(string s,int start,int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void dfs(string s,int idx,vector<string>&arr)
    {
        if(idx == s.size())
        {
            res.push_back(arr);
            return;
        }
        
        for(int i=idx;i<s.size();i++)
        {
            if(isPalindrome(s, idx, i))
            {
                arr.push_back(s.substr(idx, i - idx + 1));
                dfs(s, i + 1, arr);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>arr;
        dfs(s,0,arr);
        return res;
    }
};