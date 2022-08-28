class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size(), ret = 0, a = initialEnergy, b = initialExperience;
        for(auto i = 0; i < n; ++i) {
            if(a <= energy[i]) {
                ret += energy[i] + 1 - a;
                a = energy[i] + 1;
            }
            if(b <= experience[i]) {
                ret += experience[i] + 1 - b;
                b = experience[i] + 1;
            }
            
            a -= energy[i], b += experience[i];
        }
        
        return ret;
    }
};
