class Solution {
public:
    int mySqrt(int x) {
       
        if(x == 0) return x;
        
        int l = 1,r = x;
        int mid = x/2;
        
        while(l <= r)
        {
            if(mid == 0) break;
            
            if(x/mid < mid)
            {
                r = mid-1;
            }
            else if(x/mid > mid)
            {
                if(x/(mid+1) < mid+1)  return mid;
                else l = mid+1;
                
                
            }
            else{
                return mid;
                
            }
            mid = l + (r-l)/2;
            
        }
        return 1;
        
        
        
    }
};



/*

  Time Complexity :  O(Log n)
  Space Complexity : O(1)
  
  */
