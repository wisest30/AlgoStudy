class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        firstPlayer--, secondPlayer--;
        
        vector<set<int>> allCase(10);
        allCase[0].insert((1 << n) - 1);
        
        auto ret = vector<int>{INT_MAX, 0};
        for(auto i = 1; i < allCase.size(); ++i) {
            for(auto subset : allCase[i-1]) {
                vector<int> A;
                int f = -1, s = -1;
                for(auto i = 0; i < n; ++i) {
                    if(i == firstPlayer) f = A.size();
                    if(i == secondPlayer) s = A.size();

                    if(subset & (1 << i))
                        A.push_back(i);                    
                }

                if(s == (int)A.size() - 1 - f) {
                    ret[0] = min(ret[0], i);
                    ret[1] = max(ret[1], i);
                    continue;
                }

                for(auto x = 0; x < (1 << (A.size() / 2)); ++x) {
                    auto nxtSubset = subset;
                    for(auto i = 0; i < A.size() / 2; ++i)
                        if(x & (1 << i)) nxtSubset -= 1 << A[(int)A.size() - 1 - i];
                        else nxtSubset -= 1 << A[i];
                    if(!(nxtSubset & (1 << firstPlayer))) continue;
                    if(!(nxtSubset & (1 << secondPlayer))) continue;
                    
                    allCase[i].insert(nxtSubset);
                }
            }
        }
        
        return ret;
    }
};
