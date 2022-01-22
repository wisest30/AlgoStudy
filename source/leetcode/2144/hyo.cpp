class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ret = 0, cnt = 0;
        while(!cost.empty()) {
            if(cnt % 3 != 2) ret += cost.back();
            cost.pop_back(), ++cnt;
        }
        return ret;
    }
};
