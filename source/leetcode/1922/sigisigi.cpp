class Solution {
public:
    int countGoodNumbers(long long n) {
        int odd=1;
        const long long MOD = 1000000007;
        if(n%2==1){
           odd=5;
           n--;
        }
        if(n==0)return odd;
        unsigned long long ret=odd;
        unsigned long long adder=20;
        while(n>0){
            n=n>>1;
            if(n&1){
                ret*=adder;
                ret%=MOD;
            }
        adder=adder*adder;
        adder%=MOD;
        }
        return ret;
    }
};
