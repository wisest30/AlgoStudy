class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ret;
        int max_score = 0;
        for(auto subset = 0; subset < (1 << 12); ++subset) {
            vector<int> candi;
            int score = 0, num_a = 0;
            for(auto i = 0; i < 12; ++i) {
                if(subset & (1 << i)) {
                    score += i, num_a += aliceArrows[i] + 1;
                    candi.push_back(aliceArrows[i] + 1);
                } else {
                    candi.push_back(0);
                }
            }
            
            if(score > max_score && num_a <= numArrows) {
                for(auto& x : candi) {
                    if(x) {
                        x += numArrows - num_a;
                        break;
                    }
                }
                
                ret = candi, max_score = score;
            }
        }
        
        return ret;
    }
};
