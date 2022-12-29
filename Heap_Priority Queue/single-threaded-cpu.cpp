class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<int>res;


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>min_heap;

        vector<array<int,3>>stTasks;


        int n = tasks.size();
        for(int i=0;i<n;i++)
        {
            
           stTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(stTasks.begin(),stTasks.end());

        long long curTime = 0;
        int task = 0;

        while(task < tasks.size() || !min_heap.empty())
        {
            if(min_heap.empty() && curTime < stTasks[task][0])
            {
                curTime = stTasks[task][0];
            }


            while(task < n && curTime >= stTasks[task][0])
            {
                min_heap.push({stTasks[task][1],stTasks[task][2]});
                task++;
            }
            auto [pro,id] = min_heap.top();
            min_heap.pop();

            curTime += pro;
            res.push_back(id);

        }


        return res;
    }
};
