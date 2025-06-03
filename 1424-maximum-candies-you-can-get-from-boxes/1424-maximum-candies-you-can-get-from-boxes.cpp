class Solution {
public:
    
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        vector<bool>can_open(n),has_box(n),used(n);
        for(int i=0;i<n;i++)
        {
            can_open[i]= (status[i] == 1);
        }
        queue<int>q;
        int res = 0;
        for(int box:initialBoxes)
        {
            has_box[box] = true;
            if(can_open[box])
            {
                q.push(box);
                used[box]=true;
                res += candies[box];
            }
        }
        while(!q.empty())
        {
            int big_box = q.front();
            q.pop();
            for(int k:keys[big_box])
            {
                can_open[k] = true;
                if(!used[k] && has_box[k])
                {
                    q.push(k);
                    used[k] = true;
                    res+=candies[k];
                }
            }
            for(int box:containedBoxes[big_box])
            {
                has_box[box] = true;
                if(!used[box] && can_open[box])
                {
                    q.push(box);
                    used[box] = true;
                    res += candies[box];
                }
            }
        }
        return res;

    }
};