class Robot {
public:
    int R, C;
    int cur;
    int mod;
    bool first;
    Robot(int width, int height) {
        R = width, C = height;
        cur = 0;
        mod = R * 2 + (C - 2) * 2;
        first = true;
    }
    
    void move(int num) {
        cur = (cur + num) % mod;
        first = false;
    }
    
    vector<int> getPos() {
        if(cur >= 0 && cur < R) {
            return {cur, 0};
        } else if(cur >= R && cur < R + C - 1) {
            return {R - 1, cur - (R - 1)};
        } else if(cur >= R + C - 1 && cur < 2 * R + C - 2) {
            return {R - 1 - (cur - R - C + 2), C - 1};
        } else {
            return {0, C - 1 - (cur - R - R - C + 3)};
        }
    }
    
    string getDir() {
        if(cur == 0) return first ? "East":"South";
        else if(cur > 0 && cur < R) {
            return "East";
        } else if(cur >= R && cur < R + C - 1) {
            return "North";
        } else if(cur >= R + C - 1 && cur < 2 * R + C - 2) {
            return "West";
        } else {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
