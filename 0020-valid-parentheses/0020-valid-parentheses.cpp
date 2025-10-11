class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        unordered_map<char,char>mpp;
        mpp[')'] = '(';
        mpp['}'] = '{';
        mpp[']'] = '[';
        for(char i:s)
        {
            if(mpp.find(i) != mpp.end())
            {
                if(!stk.empty() && stk.top() == mpp[i])
                {
                    stk.pop();
                }
                else
                {
                    //cout << i << " " << stk.top() << "\n";
                    return false;
                }
            }
            else
            {
                stk.push(i);
            }
        }
        //cout << stk.size();
        return stk.empty() ? true : false;
    }
};