class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ret = 0;
        while(amount[0] || amount[1] || amount[2]) {
            sort(amount.begin(), amount.end());
            amount[2]--;
            if(amount[1])
                amount[1]--;
            ++ret;
        }
        
        return ret;
    }
};
