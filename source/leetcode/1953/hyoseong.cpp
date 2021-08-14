class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long max_val = *max_element(milestones.begin(), milestones.end());
        
        long long su = 0;
        for(auto x : milestones)
            su += x;
        su -= max_val;
        
        if(su >= max_val)
            return su + max_val;
        else
            return su * 2 + 1;
    }
};
