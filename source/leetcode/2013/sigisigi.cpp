class DetectSquares {
public:
    unordered_map<int,unordered_map<int,int>> pointMap;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        pointMap[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int curX=point[0];
        int curY=point[1];
        int ret=0;
        for(auto pairX : pointMap){
            int nextX=pairX.first;
            if(nextX==curX)continue;
            for(auto pairY : pairX.second){
                int nextY=pairY.first;
                int cnt=pairY.second;
                if(nextY==curY)continue;
                if(abs(nextY-curY)!=abs(nextX-curX))continue;
                if(pointMap.count(curX)==0 || pointMap[curX].count(nextY)==0 ||pointMap.count(nextX)==0
                   || pointMap[nextX].count(curY)==0)continue;
                cnt*=pointMap[curX][nextY];
                cnt*=pointMap[nextX][curY];
                ret+=cnt;
            }
        }
        return ret;
    }
};
