class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        for(int i=0;i<rocks.size();i++)
        {
            capacity[i] -= rocks[i];
        }

        sort(capacity.begin(),capacity.end());

        int fullBags = 0;
        for(int i=0;i<rocks.size();i++)
        {
            if(additionalRocks >= capacity[i])
            {
                additionalRocks -= capacity[i];
                fullBags++;

            }
            else
            {
                break;
            }

        }

        return fullBags;

    }
};
