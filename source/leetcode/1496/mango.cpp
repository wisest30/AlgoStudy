#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
    typedef pair<int,int> point;
    
public:
    bool isPathCrossing(string path) {
        set<point> visit;
        visit.insert(point(0, 0));
        int x = 0, y = 0;
        for(int i = 0; i< path.size(); i++){
            if( path[i] == 'N')
                y--;
            else if( path[i] == 'S')
                y++;
            else if( path[i] == 'E')
                x++;
            else
                x--;
            if( visit.count(point(x,y)))
                return true;
            visit.insert(point(x, y));
        }
        return false;
    }
};
