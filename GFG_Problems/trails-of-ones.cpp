class Solution {
  public:
    int countConsec(int n) {
        // code here
        int a = 1,b = 2;
        for(int i=2;i<=n;i++)
        {
            int t = b;
            b = a+b;
            a = t;
        }
        return pow(2,n)-b;
    }
};
