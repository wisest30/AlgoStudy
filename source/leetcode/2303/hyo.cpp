class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ret = 0;
        for(auto i = 0; i < brackets.size(); ++i) {
            if(income > brackets[i][0])
                ret += brackets[i][1] / 100.0 * (brackets[i][0] - (i ? brackets[i-1][0] : 0));
            else {
                ret += brackets[i][1] / 100.0 * (income - (i ? brackets[i-1][0] : 0));
                break;
            }
                
        }
        
        return ret;
    }
};
