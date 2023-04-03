class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());

        int i=0,j=people.size()-1;
        int res = 0;

        while(i <= j)
        {
            res++;
            if(people[i]+people[j] <= limit)
            {
                i++;
            }
            j--;
        }
        return res;
    }
};
