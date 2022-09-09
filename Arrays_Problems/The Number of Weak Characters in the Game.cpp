class Solution {
public:
    
    
    
    /*  firstly sort the given array of characters according to thier value of attack 
        if two characters have same value of attack then sort them on the basis of their defense 
        and the character having max. defense value will be placed first 
        
     */
    
    
    //Comparator function to check the above illustrated conditions
    
    bool static isGreater(vector<int>&first,vector<int>&second)
    {
        if(first[0] == second[0])
        {
            return first[1] >second[1];
        }
        return first[0] < second[0];
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        //sort on the basis of the attack value 
        
        sort(properties.begin(),properties.end(),isGreater);
        
        // intialize answer with 0 and max. of defence with least val of int
        int ans = 0,mx = INT_MIN;
        
        
        // Now iterate through all the elements and compare wether it is greater than max or less than it
        for(int i=properties.size()-1;i>=0;i--)
        {
    // if less than then simply count by one
            if(properties[i][1] < mx)
            {
                ans++;
                
            }
    // if not hten replace max eith cuurent value of defense of the current character        
            
            if(properties[i][1] > mx)
            {
                mx = properties[i][1];
            }
            
        }
        
        
        
        return ans;
        
        
/* 
   Time Complexity: O(Nlogn)
   
   Space Complexity : O(1)
   
*/
        
        
        
    }
};
