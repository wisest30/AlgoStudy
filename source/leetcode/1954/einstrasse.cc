using ll = long long;
class Solution {
public:
    ll get(int n) {
        return 2LL * n * (n+1) * (2*n+1);
    }
    long long minimumPerimeter(long long neededApples) {
        for (int i=0; i <= 100000; i++) {
            if (get(i) >= neededApples) {
                return i * 8;
            }
        }
        return 1LL;
    }
};
