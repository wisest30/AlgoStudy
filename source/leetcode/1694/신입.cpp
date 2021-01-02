class Solution {
public:
    string reformatNumber(string number) {
        string newNumber;
        
        for(char ch : number)
        {
            if(ch >= '0' && ch <= '9') newNumber += ch;
        }
        
        reverse(newNumber.begin(), newNumber.end());
        
        string ans;
        
        while(newNumber.size() > 4)
        {
            int conti = 0;
            while(conti < 3)
            {
                ans += newNumber.back();
                newNumber.pop_back();
                conti++;
            }
            ans += '-';
        }
        
        if(newNumber.size() == 2)
        {
            ans += newNumber.back();
            newNumber.pop_back();
            ans += newNumber.back();
            newNumber.pop_back();
        }
        else if(newNumber.size() == 3)
        {
            ans += newNumber.back();
            newNumber.pop_back();
            ans += newNumber.back();
            newNumber.pop_back();
            ans += newNumber.back();
            newNumber.pop_back();
        }
        else
        {
            ans += newNumber.back();
            newNumber.pop_back();
            ans += newNumber.back();
            newNumber.pop_back();
            ans += '-';
            ans += newNumber.back();
            newNumber.pop_back();
            ans += newNumber.back();
            newNumber.pop_back();
        }
        
        return ans;
    }
};
