class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        int cons = 0;
        for(auto& i : a){
            if(i%2){cons++;if(cons>2) return true;}
            else cons=0;
        }
        return false;
    }
};
