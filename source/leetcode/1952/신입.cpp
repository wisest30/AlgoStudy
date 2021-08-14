class Solution {
public:
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i == 0) return false;
        }
        return true;
    }
    
    bool isThree(int n) {
        if(n==1) return false;
        for(int i=2;i<=100;i++)
        {
            if(n == i*i && isPrime(i)) 
            {
                return true;
            }
        }
        return false;
    }
};
