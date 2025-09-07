class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1)
        {
            return {0};
        }
        vector<int>res;
        for(int i=1;i<=floor(n/2);i++)
        {
            res.push_back(i);
            res.push_back(0-i);
        }
        if(n%2)
        {
            res.push_back(0);
        }
        return res;

    }
};