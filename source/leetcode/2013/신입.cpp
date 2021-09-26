class DetectSquares {
public:
    vector<pair<int, int>> points;
    map<pair<int, int>, int> pointsMap;
    
    DetectSquares() {
            
    }
    
    void add(vector<int> point) {
        points.push_back({point[0], point[1]});
        pointsMap[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        int ret = 0;
        
        for(auto &pt : points)
        {
            if(pt.second == y && pt.first != x)
            {
                int d = x - pt.first;
                
                if(pointsMap.count({x, y-d}) && pointsMap.count({x-d, y-d})) ret += pointsMap[{x, y-d}]*pointsMap[{x-d, y-d}];
                if(pointsMap.count({x, y+d}) && pointsMap.count({x-d, y+d})) ret += pointsMap[{x, y+d}]*pointsMap[{x-d, y+d}];
            }
        }
        
        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
