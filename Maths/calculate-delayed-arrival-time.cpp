class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        
        int delt = arrivalTime + delayedTime;
        
      return delt%24;
        
    }
};
