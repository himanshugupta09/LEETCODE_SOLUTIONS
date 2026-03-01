class Solution {
public:
    int minPartitions(string n) {
        int maxNum = INT_MIN;
        for(int i=0;i<n.size();i++)
        {
            int x = n[i]-'0';
            maxNum = max(maxNum,x);
        }
        return maxNum;
    }
};