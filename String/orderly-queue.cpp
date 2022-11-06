class Solution {
public:
    string orderlyQueue(string s, int k) {
        

        if(k>1)
        {
             
            sort(s.begin(),s.end());
            return s;
        }
        else{

            string temp = s;
            s += s;

            for(int i=0;i<temp.size();i++)
            {
                temp = min(temp,s.substr(i,temp.size()));
            }

            return temp;



        }



    }
};


/* 


Time   Complexity : O(nlogn)
Space Complexity : O(N)

*/
