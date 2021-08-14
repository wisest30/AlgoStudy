class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for(auto i = 1; i * i <= n; ++i)
            if(n % i == 0)
                cnt += (i * i == n) ? 1 : 2;
        
        return cnt == 3;
    }
};
