class Solution {
public:
    bool isPathCrossing(string path) {
        set<int> s;
        int x = 0; int y = 0;
        int k = x*1e5 + y;
        s.insert(k);
        for(auto& c : path){
            if(c=='N') y++;
            if(c=='S') y--;
            if(c=='E') x++;
            if(c=='W') x--;
            k = x*1e5 + y;
            if(s.count(k)>0) return true;
            s.insert(k);
        }
        return false;
    }
};
