class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](auto l, auto r) { return growTime[l] > growTime[r]; });
        int ret = 0, su = 0;
        for(auto i : order) {
            su += plantTime[i];
            ret = max(ret, su + growTime[i]);
        }
        return ret;
    }
};
