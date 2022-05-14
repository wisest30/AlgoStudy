class Solution {
public:
    string largestGoodInteger(string num) {
        string ret;
        for(auto i = 0; i + 2 < num.size(); ++i)
            if(num[i] == num[i+1] && num[i+1] == num[i+2])
                ret = max(ret, num.substr(i, 3));
        
        return ret;
    }
};
