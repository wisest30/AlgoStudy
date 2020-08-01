class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int curEmptyBottle = numBottles;
        int ans = numBottles;
        
        while(curEmptyBottle >= numExchange)
        {
            ans += curEmptyBottle/numExchange;
            curEmptyBottle = curEmptyBottle/numExchange + curEmptyBottle%numExchange;
        }
        
        return ans;
    }
};
