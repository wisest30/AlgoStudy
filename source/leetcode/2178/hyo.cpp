class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 == 1)
            return {};

        vector<long long> ret;
        auto x = finalSum;
        for(long long i = 2; i <= finalSum; i += 2) {
            if(i <= x) {
                ret.push_back(i);
                x -= i;
            } else {
                ret[ret.size() - 1] += x;
                break;
            }
        }
        
        return ret;
    }
};
