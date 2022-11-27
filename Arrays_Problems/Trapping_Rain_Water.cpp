class Solution {
public:
    int trap(vector<int>& height) {
        
        
       // Initialize two pointers as left = 0 and right = n-1 where n is length of given array
      // also intialize thier respective max with zero
        
       int left  = 0,left_max = 0;
       int right = height.size()-1,right_max = 0;
       
       int ans = 0;  //Initailize ans with 0
       
        
       // Now iterate till left < right
        
       while(left < right)
       {
           // if bar at left is samll then right then move left pointer to ritgh by one
           if(height[left] < height[right])
           {
               // check wether it is larger than left_max or not
               // if it is then set left_max to height[left]
               
               if(height[left] >= left_max)
               {
                   left_max = height[left];
                   
               }
               else{
                   // add differnce of max && height[left] to ans
                   ans += (left_max - height[left]);
                  
                   
               }
               //move left pointer  to right  by one
                left++;
           }
           else{
               // check wether it is larger than right_max or not
               // if it is then set right_max to height[right]
               
               if(height[right] >= right_max)
               {
                   right_max = height[right];
                   
               }
               else{
                   // add differnce of max && height[right] to ans
                   ans += (right_max - height[right]);
                  
               }
               
               // move right pointer to left by one
               right--;  
           }
           
           
       }
     
       
        return ans;
        
        
        
    }
}; 
