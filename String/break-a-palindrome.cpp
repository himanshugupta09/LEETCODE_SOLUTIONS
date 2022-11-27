class Solution {
public:
    
    /*
    Approach
    
    Simply count the number of occurrences of 'a' in the given string, 
    if all the characters are 'a' or n-1 characters are 'a' replace the 
    last character with 'b', else search for the first character which is 
    not 'a' and replace that character with 'a' to get lexicographically smallest.
    
    */
    
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size();
        
        if(n == 1)
        {
            return "";
            
        }
        int ac  = 0;
        
        for(auto i:palindrome)
        {
            if(i == 'a')
            {
                ac++;
                
            }
        }
        
        if(ac >= n-1)
        {
            palindrome[n-1] = 'b';
            return palindrome;
            
        }
        
        for(int i=0;i<(n+1)/2;i++)
        {
            if(palindrome[i] != 'a' && palindrome[i] == palindrome[n-i-1])
            {
                palindrome[i] = 'a';
                break;
            }
        }
        
        
        return palindrome;
        
        
        
    }
};
