class Solution {
public:
    int pivotInteger(int n) {
        
        int leftV = 1;
        int rightV = n;
        int lsm = leftV;
        int rsm = rightV;
        
        if(n == 1) return 1;
        
        while(leftV < rightV)
        {
            if(lsm < rsm)
            {
                leftV++;
                lsm += leftV;
            }
            else
            {
                rightV--;
                rsm += rightV;
            }
            if(lsm == rsm && (leftV+1 == rightV-1))
            {
                return leftV+1;
            }
        }
        return -1;
        
    }
};
