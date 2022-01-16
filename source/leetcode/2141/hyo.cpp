class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long su = accumulate(batteries.begin(), batteries.end(), 0ll);
        while(batteries.back() > su / n) {
            n--, su -= batteries.back();
            batteries.pop_back();
        }
        return su / n;
    }
};
