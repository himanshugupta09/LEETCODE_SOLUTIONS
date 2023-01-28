class SummaryRanges {

    set<int>mySet;

public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        mySet.insert(value);
    }
    
    vector<vector<int>> getIntervals() {

        if(mySet.empty())
        {
            return {};
        }
        vector<vector<int>>result;

        int left = -1,right = -1;

        for(int val:mySet)
        {
            if(left < 0)
            {
                left = right = val;
            }
            else if(val == right+1)
            {
                right = val;
            }
            else
            {
                result.push_back({left,right});
                left = right = val;
            }
        }
        result.push_back({left,right});
        return result;


    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
