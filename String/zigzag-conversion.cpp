class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
        {
            return s;
            
        }
        
        vector<string>fin(min(numRows,int(s.size())));
        
        int cur_row = 0;
        bool toDown = false;
        
        for(char i:s)
        {
            fin[cur_row] += i;
            
            if(cur_row == 0 || cur_row == numRows-1)
            {
                toDown = !toDown;
                
            }
            cur_row += toDown?1:-1;
            
            
            
        }
        
        string res;
        
        for(string r:fin)
        {
            res += r;
        }
        
        return res;
        
        
        
    }
};
