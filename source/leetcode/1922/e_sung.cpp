class Solution {
public:
    long long modulo = 1000000007;
    long long pow_dynamic(int a, long long n){

        if(n == 1)
            return a;
        else if(n == 0)
            return 1;
        long long res = (pow_dynamic(a,n/2) % modulo);
        if(n % 2 == 0){
            return (res * res) % modulo;
        }
        else{
            return (a * res * res) % modulo;
        }
/* Time limit
        else if(n % 2 == 0){
            res = ((pow_dynamic(a,n/2) % modulo) * (pow_dynamic(a,n/2) % modulo)) % modulo;
        }
        else if(n % 2 != 0){
            res = (a * (pow_dynamic(a,n/2) % modulo) * (pow_dynamic(a,n/2) % modulo)) % modulo;
        }
*/
    }
    int countGoodNumbers(long long n) {
        if(n % 2 == 0)
            return ((pow_dynamic(5,n/2) % modulo) * (pow_dynamic(4,n/2) % modulo)) % modulo;
        else
            return (5 * (pow_dynamic(5,n/2) % modulo) * (pow_dynamic(4,n/2) % modulo)) % modulo;
    }
};

/* 1st code not accepted
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long int ret = 1;
        long long int modulo = 1000000007;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                ret = ((ret % modulo) * ( 5 % modulo)) % modulo;
            else
                ret = ((ret % modulo) * ( 4 % modulo)) % modulo;
        }
        return ret;
    }
};
*/
