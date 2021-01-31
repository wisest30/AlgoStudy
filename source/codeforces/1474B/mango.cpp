//
//  696_Div2_B.cpp
//  Codeforces
//
//  Created by mangoxb on 2021/01/31.
//
 
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void findPrimes(vector<int>& primes, int max_range){
    vector<int> nums(max_range + 1);
    for(int i = 2; i * i <= max_range; i++){
        if( nums[i] )
            continue;
        for(int j = i * i; j <= max_range; j+= i)
            nums[j] = 1;
    }
    for(int i = 2; i <= max_range; i++){
        if( !nums[i])
            primes.push_back(i);
    }
}
 
void differentDivisor(){
    int tc;
    vector<int> primes;
    findPrimes(primes, 30000);
    
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        int first_prime = *lower_bound(primes.begin(), primes.end(), 1 + n);
        int second_rpime = *lower_bound(primes.begin(), primes.end(), first_prime + n);
        cout << first_prime * second_rpime << "\n";
    }
}
 
 
int main(){
    // freopen("input.txt","r",stdin);
    differentDivisor();
    return 0;
}
