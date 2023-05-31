class UndergroundSystem {
public:

    unordered_map<int,pair<string,int>>chin;
    unordered_map<string,pair<int,int>>chout;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        chin[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto cIn = chin[id];
        chin.erase(id);

        string path = cIn.first + "_" + stationName;
        chout[path].first += t - cIn.second;
        chout[path].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = startStation + "_" + endStation;
        auto time = chout[path];

        return (double)time.first/time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
