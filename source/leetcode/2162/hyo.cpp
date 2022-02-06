class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int ret = INT_MAX;
        for(auto min = 0; min * 60 <= targetSeconds; ++min) {
            auto sec = targetSeconds - min * 60;
            if(min >= 100 || sec >= 100) continue;
            auto A = vector<int>{min / 10, min % 10, sec / 10, sec % 10};
            int i = 0;
            while(i < A.size() && A[i] == 0) ++i;
            int cur = startAt, cost = 0;
            for(; i < A.size(); ++i) {
                if(cur != A[i]) cost += moveCost;
                cost += pushCost;
                cur = A[i];
            }
            ret = std::min(ret, cost);
        }
        return ret;
    }
};
