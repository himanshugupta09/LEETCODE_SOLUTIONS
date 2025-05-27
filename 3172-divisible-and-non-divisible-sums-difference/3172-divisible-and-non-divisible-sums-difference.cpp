class Solution {
public:
    int differenceOfSums(int n, int m) {
        int notD = 0,div = 0;
        for(int i=1;i<=n;i++)
        {
            if(i%m)
            {
                notD += i;
            }
            else
            {
                div += i;
            }
        }
        return (notD-div);
        
    }
};