class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string>matrix(min(numRows,n));
        int row_num = 0;
        int dir = 1;
        int m = matrix.size();
        if(numRows == 1)
        {
            return s;
        }
        for(auto ch:s)
        {
            
            if(row_num <= m-1 && dir == 1)
            {
                matrix[row_num].push_back(ch);
                row_num++;
                if(row_num == m)
                {
                    row_num--;
                    dir = 0;
                }

            }
            else if(row_num > 0 && dir == 0)
            {
                row_num--;
                matrix[row_num].push_back(ch);
                if(row_num <= 0)
                {
                    dir = 1;
                    row_num++;
                }
                
            }
        }
        string res;
        for(int i=0;i < matrix.size();i++)
        {
            //cout << matrix[i]  << "\n";
            res += matrix[i];
        }
        return res;
    }
};