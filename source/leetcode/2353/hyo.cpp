class FoodRatings {
public:
    map<string, int> r;
    map<string, string> t;
    map<string, set<pair<int, string>>> m;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(auto i = 0; i < n; ++i) {
            r[foods[i]] = ratings[i];
            t[foods[i]] = cuisines[i];
            m[cuisines[i]].insert(make_pair(-ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        auto old_r = r[food];
        auto type = t[food];
        
        m[type].erase(make_pair(-old_r, food));
        r[food] = newRating;
        m[type].insert(make_pair(-newRating, food));
    }
    
    string highestRated(string cuisine) {
        return m[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
