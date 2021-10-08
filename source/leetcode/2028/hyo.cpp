class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int remain = mean * (m + n);
        for(auto x : rolls)
            remain -= x;

        vector<int> ret(n, 1);
        remain -= n;
        
        if(remain < 0)
            return {};
        
        for(auto i = 0; i < n; ++i)
            while(ret[i] < 6 && remain)
                ++ret[i], --remain;

        return remain ? vector<int>{} : ret;
    }
};
