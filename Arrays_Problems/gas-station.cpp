class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totGas = 0;
        int totCost = 0;

        for(int i=0;i<gas.size();i++)
        {
            totGas += gas[i];
            totCost += cost[i];

        }

        if(totGas < totCost)
        {
            return -1;
        }

        int startIdx = 0;
        int curFuel = 0;

        for(int i=0;i<gas.size();i++)
        {

            if(curFuel < 0)
            {
                curFuel = 0;
                startIdx = i;
            }
            curFuel += (gas[i] - cost[i]);
        }

        return startIdx;
    }
};
