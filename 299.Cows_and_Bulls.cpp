class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char,int>u1,u2;
        
        int bull  = 0;
        int cow = 0;
        
        
        for(int i = 0;i<guess.size();i++)
        {
            if(secret[i] == guess[i])
            {
                bull++;
            }
            else{
                u1[secret[i]]++;
                u2[guess[i]]++;
                
            }
        }
        
        for(char i='0';i<='9';i++)
        {
            cow += min(u1[i],u2[i]);
            
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
        
    }
};
