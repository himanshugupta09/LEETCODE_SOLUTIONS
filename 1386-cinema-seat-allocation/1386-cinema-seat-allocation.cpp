class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>>mpp;
        for(auto seat:reservedSeats)
        {
            mpp[seat[0]].insert(seat[1]);
        }
        int res = (n-mpp.size())*2;
        cout << res;
       
        for(auto row:mpp)
        {
            bool left = true;
            bool right = true;
            bool mid = true;
            set<int>st = row.second;
            for(int i=2;i<=5;i++)
            {
                if(st.find(i) != st.end()){
                    left = false;
                    break;
                }
            }
            for(int i=4;i<=7;i++)
            {
                if(st.find(i) != st.end()){
                    mid = false;
                    break;
                }
            }
            for(int i=6;i<=9;i++)
            {
                if(st.find(i) != st.end()){
                    right = false;
                    break;
                }
            }
            if(left && right){
                res += 2;
            }
            else if(left || right || mid){
                res++;
            }
        }

        return res;
    }
};