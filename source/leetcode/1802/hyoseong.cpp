class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto check = [&](long long m) {
            long long min_sum = m;
            long long cnt = index;
            min_sum += cnt > m - 1 ? (m-1) * m / 2 + cnt - (m - 1) : cnt * (m - cnt + m - 1) / 2;
            cnt = n - (index + 1);
            min_sum += cnt > m - 1 ? (m-1) * m / 2 + cnt - (m - 1) : cnt * (m - cnt + m - 1) / 2;
            
            return min_sum <= maxSum;
        };
        
        long long l = 1, r = maxSum + 1;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m))
                l = m;
            else
                r = m;
        }
        
        return l;
    }
};
