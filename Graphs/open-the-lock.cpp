class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string>vis(deadends.begin(),deadends.end());
       
         unordered_map<char, char> nex = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };
        unordered_map<char, char> pre = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };
        queue<string>q;
        q.push("0000");
        
        int turns=0;
        
        if(vis.find("0000") != vis.end())
        {
            return -1;
        }
        vis.insert("0000");
        
        while(!q.empty())
        {
            for(int c=q.size();c > 0;c--)
            {
                string curC = q.front();
                q.pop();
                if(curC == target)
                {
                    return turns;
                }
                for(int w=0;w<4;w++)
                {
                    string newC = curC;
                    newC[w] = nex[newC[w]];
                    
                    if(vis.find(newC) == vis.end())
                    {
                        q.push(newC);
                        vis.insert(newC);
                    }
                    
                    newC = curC;
                    newC[w] = pre[newC[w]];
                    if(vis.find(newC) == vis.end())
                    {
                        q.push(newC);
                        vis.insert(newC);
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};
