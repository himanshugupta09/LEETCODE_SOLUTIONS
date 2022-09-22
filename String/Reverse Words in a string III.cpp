class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string t, ans;
        
        while (getline(ss, t, ' ')) {
            reverse(t.begin(), t.end());
            ans += t + ' ';
        }
       
        return ans.substr(0, ans.size() - 1); 
    }
};
