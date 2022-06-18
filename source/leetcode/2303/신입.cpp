class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        int upper = 0;
        
        for(auto& bracket : brackets)
        {
            int realPay = min(bracket[0] - upper, income);
            
            tax += 1.0 * realPay * bracket[1] / 100;
            upper = bracket[0];
            income -= realPay;
            
            if(income == 0) break;
        }
        
        return tax;
    }
};
