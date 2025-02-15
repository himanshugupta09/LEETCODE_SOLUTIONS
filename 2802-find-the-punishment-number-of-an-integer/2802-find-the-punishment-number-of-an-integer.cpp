class Solution {
public:
    
    bool canPart(string number,int num)
    {
        int n = number.size();
        if(num == 0 && n == 0)
        {
            return true;
        }
        if(num < 0)
        {
            return false;
        }
        for(int i=0;i<number.size();i++)
        {
            string left = number.substr(0,i+1);
            string right = number.substr(i+1);
            int leftN = stoi(left);
            if(canPart(right,num-leftN)) return true;
        }
        return false;


    }
    int punishmentNumber(int n) {
        int punishNum = 0;
        
        for(int i=1;i<=n;i++)
        {
            int sqr = i*i;
            if(canPart(to_string(sqr),i))
            {
                punishNum += sqr;
            }
        }
        return punishNum;
        
    }
};