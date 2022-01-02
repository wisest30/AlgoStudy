class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& A) {
        long long cur = mass;
        sort(A.begin(), A.end());
        for(auto a : A) {
            if(a > cur) return false;
            cur += a;
        }
        return true;
    }
};
