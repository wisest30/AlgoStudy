class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int su = 0;
        int ret = 0;
        for(auto& t : tiles) {
            su += t[1] - t[0] + 1;
            t.push_back(su);
            
            auto left = t[1] - carpetLen + 1;
            auto p = lower_bound(tiles.begin(), tiles.end(), vector<int>{left});
            
            int candi = t[2] - (*p)[2] + (*p)[1] - (*p)[0] + 1;
            if(p != tiles.begin()) {
                p = prev(p);
                if((*p)[1] >= left)
                    candi += (*p)[1] - left + 1;
            }
            
            ret = max(ret, candi);
        }
        
        return ret;
    }
};
