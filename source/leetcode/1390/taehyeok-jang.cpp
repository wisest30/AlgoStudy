
class Solution {
public:
    // only num (a*b, a!=b) has four divisors (a, b is prime number)
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto n: nums) {
            int a = -1;
            for(int d=2; d*d<=n; d++) {
                if(n%d==0) {
                    if(a==-1) {
                        a = d;
                    } else {
                        a = -1;
                        break;
                    }
                }
            }
            if(a!=-1&&(a!=n/a)) {
                sum += (1 + n + a + n/a);
            }
        }
        return sum;
    }
};

