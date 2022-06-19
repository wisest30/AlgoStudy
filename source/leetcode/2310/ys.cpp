class Solution {
private:
    static constexpr int UNSET = 12345;

public:
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        
        std::vector<int> cache(num + 1, UNSET);
        
        int current = k;
        std::vector<int> targets;
        while (current <= num) {
            cache[current] = 1;
            targets.push_back(current);
            current += 10;
        }
        
        for (int i = 0; i <= num; ++i) {
            for (int j = 0; j < targets.size(); ++j) {
                if (i < targets[j] || cache[i - targets[j]] == UNSET) {
                    continue;
                }
                
                cache[i] = std::min(cache[i], cache[i - targets[j]] + 1);
            }
        }
        
        return cache[num] == UNSET ? -1 : cache[num];
    }
};
