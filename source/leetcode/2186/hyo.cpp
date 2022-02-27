class Solution {
public:
    int minSteps(string s, string t) {
        map<int, int> counter;
        for(auto c : s) counter[c]++;
        for(auto c : t) counter[c]--;
        
        return accumulate(counter.begin(), counter.end(), 0, [](auto& acc, auto& p) { return acc + abs(p.second); });
    }
};
