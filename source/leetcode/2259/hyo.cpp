class Solution {
public:
    string removeDigit(string number, char digit) {
        string ret = "";
        for(auto i = 0; i < number.size(); ++i)
            if(number[i] == digit)
                ret = max(ret, number.substr(0, i) + number.substr(i+1, number.size() - (i+1)));
        
        return ret;
    }
};