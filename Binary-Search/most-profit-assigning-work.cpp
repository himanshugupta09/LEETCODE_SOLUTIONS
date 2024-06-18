class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int res = 0;
        
        /*
        // Approach with  memoization
        */
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        // Sort jobs based on difficulty
        sort(jobs.begin(), jobs.end());
        
        // Update jobs to have the maximum profit achievable at each difficulty
        for (int i = 1; i < n; ++i) {
            jobs[i].second = max(jobs[i].second, jobs[i-1].second);
        }
        
        // Sort worker abilities
        sort(worker.begin(), worker.end());
        
        // Use a two-pointer technique to find the maximum profit
        int j = 0;
        for (int i = 0; i < worker.size(); ++i) {
            while (j < n && jobs[j].first <= worker[i]) {
                ++j;
            }
            if (j > 0) {
                res += jobs[j-1].second;
            }
        }
        
        return res;
    }
};


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobProfile;
        for (int i = 0; i < difficulty.size(); i++) {
            jobProfile.push_back({difficulty[i], profit[i]});
        }
        /*
        // Appraoch with Greedy Two pointers
        
        */
        // Sort both worker and jobProfile arrays
        sort(worker.begin(), worker.end());
        sort(jobProfile.begin(), jobProfile.end());

        int netProfit = 0, maxProfit = 0, index = 0;
        for (int i = 0; i < worker.size(); i++) {
            // While the index has not reached the end and worker can pick a job
            // with greater difficulty move ahead.
            while (index < difficulty.size() and
                   worker[i] >= jobProfile[index].first) {
                maxProfit = max(maxProfit, jobProfile[index].second);
                index++;
            }
            netProfit += maxProfit;
        }
        return netProfit;
    }
};
