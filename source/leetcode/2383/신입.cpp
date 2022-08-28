class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExp, vector<int>& energy, vector<int>& exp) {
        int curEnergy = initialEnergy;
        int curExp = initialExp;
        
        int n = energy.size();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(curEnergy <= energy[i])
            {
                int target = energy[i]+1;
                ans += target - curEnergy;
                curEnergy = target;
            }
            curEnergy -= energy[i];
            
            if(curExp <= exp[i])
            {
                int target = exp[i]+1;
                ans += target - curExp;
                curExp = target;
            }
            curExp += exp[i];
        }
        
        return ans;
    }
};
