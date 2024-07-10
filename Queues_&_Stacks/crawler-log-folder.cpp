class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>stk;
        
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i] != "../" && logs[i] != "./")
            {
                stk.push(logs[i]);
            }
            else
            {
                if(logs[i] == "../" && !stk.empty())
                {
                    stk.pop();
                }
                else if(logs[i] == "./")
                {
                    continue;
                }
            }
        }
        return stk.size();
    }
};
