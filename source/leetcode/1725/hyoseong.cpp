class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& A) {
        map<int, int> m;
        for(auto& a : A)
            m[min(a[0], a[1])]++;
        
        return (*m.rbegin()).second;
    }
};
