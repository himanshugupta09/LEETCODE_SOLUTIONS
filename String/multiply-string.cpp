class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        
        int n = num1.size() + num2.size();
        string res(n, '0');
        
        for (int place2 = 0; place2 < num2.size(); place2++) {
            int digit2 = num2[place2] - '0';
            
            for (int place1 = 0; place1 < num1.size(); place1++) {
                int digit1 = num1[place1] - '0';
                
               
                int numZeros = place1 + place2;
                
                
                int carry = res[numZeros] - '0';
                int multiplication = digit1 * digit2 + carry;
                
                
                res[numZeros] = (multiplication % 10) + '0';
                
                res[numZeros + 1] += (multiplication / 10);
            }
        }
        
        if (res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
