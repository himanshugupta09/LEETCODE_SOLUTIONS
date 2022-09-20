 /*
    here we will use a monotonic stack in this we will
    dierectly push if stck is empyt else if not then we 
    will compare the new elemnt from  array to top of the 
    stack if it  is greater than top of stack then we pop 
    else we again push it to stack 
    
    iterate from the last to first and form the monotonic stack
    
    */
    
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        if(n==2){
            if(nums[0]<=nums[1])return 1;
            return 0;
        }
        stack<int>s;
        for(int i=0;i<n;i++){
            if(s.empty()||nums[i]<nums[s.top()]){s.push(i);}  
        }
        int ramp=0;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]>=nums[s.top()] ){    
                ramp=max(ramp,i-s.top());
                s.pop();
            }
        }
        return ramp;
    }
};    
