class Solution {
public:
    long solves(int a,int b,char op)
    {
        if(op == '+') return a + b;
        else if(op == '-') return a-b;
        else if(op == '*') return (long)a*b;
        return a/b;
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<long>stk;
        int n = tokens.size();
        
        set<string> oper = {"+", "-", "*", "/"};
        
        for(int i=0;i<n;i++)
        {
            if(oper.find(tokens[i]) != oper.end())
            {
                long n2 = stk.top();
                stk.pop();
                long n1 = stk.top();
                stk.pop();
                
                long res = solves(n1,n2,tokens[i][0]);
                stk.push(res);
            }
            else
            {
                stk.push(stoi(tokens[i]));
            }
            
        }
        
        return stk.top();
        
    }
};
