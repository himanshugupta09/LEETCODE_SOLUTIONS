class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        map<int,int>mp;
       

        for(int i=0;i<tasks.size();i++)
        {
            if(mp.find(tasks[i]) != mp.end())
            {
                mp[tasks[i]]++;
                
            }
            else
            {
                mp[tasks[i]] = 1;
                
            }
        }
        int nc = 0;

        for(auto i:mp)
        {
            if(i.second == 1)
            {
                return -1;
            }
            else if(i.second % 3 == 0)
            {
                nc += i.second/3;
            }
            else
            {
                nc += i.second/3 + 1;
            }
        }
        return nc;

    }
};
