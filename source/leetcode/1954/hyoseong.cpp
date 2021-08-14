class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        auto s = [](long long n) {
            return n * (n + 1) / 2;
        };
        
        auto f = [&](long long n) {
            return (s(n * 2) - s(n - 1) + s(n * 2 - 1) - s(n)) * 4;
        };
        
        long long su = 0;
        for(long long i = 1;;++i) {
            su += f(i);
            if(su >= neededApples)
                return i * 2 * 4;
        }
        
        return -1;
    }
};
