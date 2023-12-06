class Solution {
public:
    int totalMoney(int n) {
        
         int total = 0;
    int day = 1;
    int deposit = 1;

    while (day <= n) {
        total += deposit;
        deposit++;

        if (day % 7 == 0) {
            deposit = day / 7 + 1;
        }

        day++;
    }

    return total;
    }
};
