class Solution {
public:
    string largestPalindromic(string num) {
        int cnts[10] = {0,};
        for(auto n: num)
            ++cnts[n - '0'];
        
        string left;
        for(auto i = 9; i >= 0; --i)
            while(cnts[i] >= 2)
                cnts[i] -= 2, left.push_back(i + '0');
        
        string mid;
        for(auto i = 9; i >= 0 && mid.empty(); --i)
            if(cnts[i])
                mid.push_back(i + '0');
        
        string ret = left + mid;
        ret.insert(ret.end(), left.rbegin(), left.rend());
        
        if(ret.front() == '0')
            return mid.empty() ? "0" : mid;
        else 
            return ret;
    }
};
