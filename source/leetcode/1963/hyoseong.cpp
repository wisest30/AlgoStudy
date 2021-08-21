class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0;
        for(auto c : s) {
            if(c == ']')
                open ? open-- : close++;
            else
                open++;
        }
        
        return (open + 1) / 2;
    }
};
