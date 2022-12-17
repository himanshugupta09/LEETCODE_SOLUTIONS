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

        stack<long>s;
        int n = tokens.size();

        for(int i=0;i<n;i++)
        {
            if(tokens[i].size() == 1 && tokens[i][0] < 48)
            {
                long n2 = s.top();
                s.pop();
                long n1 = s.top();
                s.pop();

                string op = tokens[i];
                long solver = solves(n1,n2,op[0]);
                s.push(solver);

            }
            else
            {
                s.push(stoi(tokens[i]));

            }
        }

        return s.top();

        
    }
};
