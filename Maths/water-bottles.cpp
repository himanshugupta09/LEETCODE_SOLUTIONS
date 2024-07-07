class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        while(numBottles >= numExchange)
        {
            res += numExchange;
            numBottles-=numExchange;
            numBottles++;
        }
        return res+numBottles;
    }
};
