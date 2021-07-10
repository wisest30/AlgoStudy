class Solution {
public:
    static constexpr int MAX_KEY_SIZE = 1 << 10;
    long long wonderfulSubstrings(string word) {
        int n = word.size();

        vector<long long> A(MAX_KEY_SIZE);
        A[0]++;

        vector<vector<int>> matchingKey(MAX_KEY_SIZE);
        for(auto i = 0; i < MAX_KEY_SIZE; ++i)
            for(auto j = 0; j < MAX_KEY_SIZE; ++j)
                if(__builtin_popcount(i ^ j) <= 1)
                    matchingKey[i].push_back(j);

        int key = 0;
        long long ret = 0;
        for(auto i = 0; i < n; ++i) {
            key ^= 1 << (word[i] - 'a');

            for(auto k : matchingKey[key])
                ret += A[k];
            
            A[key]++;
        }
        
        return ret;
    }
};
