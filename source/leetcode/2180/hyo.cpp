class Solution {
public:
    int countEven(int num) {
        int ret = 0;
        
        for(auto i = 1; i <= num; ++i) {
            auto su = 0;
            for(auto c : to_string(i))
                su += c - '0';
            
            if(su % 2 == 0)
                ++ret;
        }
        
        return ret;
    }
};
