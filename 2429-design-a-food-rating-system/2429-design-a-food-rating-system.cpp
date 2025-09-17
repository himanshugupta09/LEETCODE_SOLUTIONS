class FoodRatings {
    unordered_map<string,int>foodRat;
    unordered_map<string,string>foodCus;
    
    unordered_map<string,set<pair<int,string>>>cusFood;
    
    
public:
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i=0;i<foods.size();i++)
        {
            foodRat[foods[i]] = ratings[i];
            foodCus[foods[i]] = cuisines[i];
            
            cusFood[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cusiName = foodCus[food];
        auto oldIter = cusFood[cusiName].find({-foodRat[food],food});
        cusFood[cusiName].erase(oldIter);
        foodRat[food] = newRating;
        
        cusFood[cusiName].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        
        auto higher = *cusFood[cuisine].begin();
        return higher.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */