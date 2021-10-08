class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> A(3);
        for(auto x : stones)
            A[x % 3]++;
        
        for(auto i = 1; i <= 2; ++i) {
            if(A[i] == 0)
                continue;
            
            auto a = A;
            a[i]--;
            auto round = a[0] + 1;
            int su = i;
            while(true) {
                if(a[1] && (su + 1) % 3 != 0)
                    round++, a[1]--, su += 1;
                else if(a[2] && (su + 2) % 3 != 0)
                    round++, a[2]--, su += 2;
                else
                    break;
            }
            
            if(round < stones.size() && round % 2)
                return true;
        }
        
        return false;
    }
};
