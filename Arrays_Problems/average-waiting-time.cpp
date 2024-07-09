class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n =  customers.size();
        
        double totWait = 0;
        
        int last = customers[0][0]+customers[0][1];
        totWait = last-customers[0][0];
        
        for(int i=1;i<n;i++)
        {
            last = max(last, customers[i][0]) + customers[i][1]; 
            totWait += max(last, customers[i][0]) - customers[i][0];
        }
        return totWait/n;
    }
    
};
