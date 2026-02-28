class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int min_dif = INT_MAX;
        int num1 = -1,num2 = -1;
        
        int n = arr1.size();
        int m = arr2.size();
        int i = 0,j = m-1;
        while(i < n && j >= 0)
        {
            int sum = arr1[i]+arr2[j];
            int dif = abs(x-sum);
            if(dif < min_dif)
            {
                num1 = arr1[i];
                num2 = arr2[j];
                
                if(dif == 0)
                {
                    return {num1,num2};
                }
                min_dif = dif;
            }
            if(sum < x) i++;
            else j--;
        }
        return {num1,num2};
        
    }
};
