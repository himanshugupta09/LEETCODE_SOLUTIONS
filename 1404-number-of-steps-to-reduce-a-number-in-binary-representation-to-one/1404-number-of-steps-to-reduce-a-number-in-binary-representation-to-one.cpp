class Solution {
public:
    int numSteps(string s) {

        int steps = 0;
        int carry = 0;
        for(int i=s.size()-1;i>=1;i--)
        {
            int dig = s[i]-'0' + carry;
            if(dig&1)
            {
                steps += 2;
                carry = 1;
            }
            else
            {
                steps++;
            }
        } 
        return steps+carry;
    }
};