class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string res;

        while(columnNumber)
        {
            columnNumber--;
            res = res + (char)((columnNumber)%26 + 'A');
            columnNumber = columnNumber/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
