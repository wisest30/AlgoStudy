class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> s;
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < n; ++j)
                for(auto k = 0; k < n; ++k)
                    if(i != j && j != k && k != i && digits[i] && digits[k] % 2 == 0)
                        s.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
        
        return vector(s.begin(), s.end());
    }
};
