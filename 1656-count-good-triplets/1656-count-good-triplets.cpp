class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x = abs(arr[i]-arr[j]);
                for(int k=j+1;k<n;k++)
                {
                   int y = abs(arr[j]-arr[k]);
                   int z = abs(arr[k]-arr[i]);
                   if(x <= a && y <= b && z <= c)
                   {
                        res++;
                   }
                }
            }
        }
        return res;
    }
};