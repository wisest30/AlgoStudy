class Solution {
public:
    typedef long long ll;
    
    long long numberOfWeeks(vector<int>& milestones) {
        sort(milestones.rbegin(), milestones.rend());
        
        ll sum = 0;
        
        for(int i=1;i<milestones.size();i++) sum += 0LL + milestones[i];  
        if(milestones[0] > sum + 1) return sum + sum + 1;
        return sum + milestones[0];
    }
};
