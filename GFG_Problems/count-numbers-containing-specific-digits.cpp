class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
     bool zero = 0;
        for(int i:arr){
            if(i == 0){
                zero = 1;
                break;
            }
        }
        
        int tot = pow(10, n-1)*9;
        int m = 10-arr.size();
        int notPos = pow(m, n-1)*(zero?m:m-1);
        
        return tot-notPos;   
    }
};
