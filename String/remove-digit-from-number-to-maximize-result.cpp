class Solution {
public:
    string removeDigit(string number, char digit) {
        
        string res = "";
        int n = number.size();

        for(int i=n-1;i>=0;i--)
        {
            if(number[i] == digit)
            {
                string temp = number.substr(0, i) + number.substr(i+1, n);
                res = max(res, temp);
            }
        }
        return res;
        
    }
};
