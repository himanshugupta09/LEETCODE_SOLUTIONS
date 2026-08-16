class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int res = 0;
        int last = 0;
        for(int i:requests){
            res += abs(i-last);
            last = i;
        }
        return res;
    }
};