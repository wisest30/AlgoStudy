class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int status = 0;
        int n = num.size();
        
        for(auto i = 0; i < n; ++i) {
            auto x = num[i] - '0';
            auto y = change[x];
            if(x < y) {
                if(status == 0)
                    num[i] = y + '0', status = 1;
                else if(status == 1)
                    num[i] = y + '0';
            }
            else if(x > y) {
                if(status == 0); //pass
                else if(status == 1)
                    status = 2;
            }
        }
        
        return num;
    }
};
