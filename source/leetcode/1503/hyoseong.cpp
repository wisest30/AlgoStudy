class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        auto ret = 0;
        for(auto l : left) ret = max(ret, l);
        for(auto r : right) ret = max(ret, n - r);
        return ret;
    }
};
