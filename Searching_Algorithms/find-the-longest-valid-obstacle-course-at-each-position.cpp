class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        vector<int>cur;
        int n  = obstacles.size();
        vector<int>res(n);

        for(int i=0;i<n;i++)
        {
            int vl = obstacles[i];

            if(cur.size() == 0 || cur.back() <= vl)
            {
                cur.push_back(vl);
                res[i] = cur.size();
            }
            else
            {
                int idx = upper_bound(cur.begin(),cur.end(),vl) - cur.begin();
                cur[idx] = vl;
                res[i] = idx+1;
            }
        }
        return res;
    }
};
