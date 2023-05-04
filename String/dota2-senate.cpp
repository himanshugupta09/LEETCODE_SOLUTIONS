class Solution {
public:

    
    string predictPartyVictory(string senate) {

        int n = senate.size();
        int dc = count(senate.begin(),senate.end(),'D');
        int rc = count(senate.begin(),senate.end(),'R');

        queue<int>rq,dq;

        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
            {
                rq.push(i);
            }
            else
            {
                dq.push(i);
            }
        }

        while(!rq.empty() && !dq.empty())
        {
            int ri = rq.front();
            rq.pop();
            int di = dq.front();
            dq.pop();

            if(ri < di)
            {
                rq.push(ri+n);
            }
            else
            {
                dq.push(di+n);
            }
        }

        return (rq.size() > dq.size()) ? "Radiant" : "Dire";
    }
};
