class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>stk;
        

        for(auto rock:asteroids)
        {
            bool fg = true;
            while(!stk.empty() && (stk.top() > 0 && rock < 0))
            {
                if(abs(stk.top()) < abs(rock))
                {
                    stk.pop();
                    continue;
                }
                else if(abs(stk.top()) == abs(rock))
                {
                    stk.pop();
                }
                fg = false;
                break;

            }  
            if(fg)
            {
                stk.push(rock);
            } 
        }
        vector<int>res;
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        if(res.size()>1) reverse(res.begin(),res.end());
        return res;
    }
};
