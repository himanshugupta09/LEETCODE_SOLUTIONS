class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>stk;
        string res;
        for(int i=0;i<path.size();i++)
        {
            if(path[i] == '/')
            {
                continue;
            }
            string temp;

            while(i < path.size() && path[i] != '/')
            {
                temp += path[i];
                ++i;
            }
            if(temp == ".")
            {
                continue;
            }
            else if(temp == "..")
            {
                if(!stk.empty())
                {
                    stk.pop();
                }

            }
            else
            {
                stk.push(temp);
            }
        }
        while(!stk.empty())
        {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        
        if(res.size() == 0)
            return "/";
        return res;


        
    }
};
