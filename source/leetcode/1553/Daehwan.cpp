class Solution {
public:
    int minDays(int n) {
    unordered_map<int,int> dp;
        function<int(int)> search = [&](int n)->int{
        if(n<=1) return 1;
        if(dp.count(n)>0) return dp[n];
        return dp[n] = 1+min(n%2+search(n/2), n%3+search(n/3));
        };
        return search(n);
    }
};
