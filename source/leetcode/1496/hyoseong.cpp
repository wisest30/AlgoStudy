class Solution {
public:
    bool isPathCrossing(string path) {
        auto y = 0, x = 0;
        set<pair<int, int>> S;
        S.insert({0, 0});
        for(auto p : path) {
            if(p == 'N') y++;
            else if(p == 'S') y--;
            else if(p == 'E') x++;
            else if(p == 'W') x--;
            if(S.count({y, x})) return true;
            S.insert({y,x});
        }
        return false;
    }
};
