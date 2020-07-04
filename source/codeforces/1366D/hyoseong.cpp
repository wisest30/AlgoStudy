#include<bits/stdc++.h>
 
using namespace std;

vector<long long> get_minFactor(long long max_n) {
    assert(max_n >= 0);

    if(max_n == 0)
        return {-1};
    if(max_n == 1)
        return {-1, -1};
    if(max_n == 2)
        return {-1, -1, 2};

    auto minFactor = vector<long long>(max_n + 1);
    iota(minFactor.begin(), minFactor.end(), 0);
    minFactor[0] = minFactor[1] = -1;

    for(long long i = 2; i * i <= max_n; ++i)
        if(minFactor[i] == i)
            for(long long j = i * i; j <= max_n; j += i)
                if(minFactor[j] == j)
                    minFactor[j] = i;
    
    return minFactor;
}

void solve(int TestCase) {
    auto minFactor = get_minFactor(1e7);

    int n;
    scanf("%d", &n);
    auto A = vector<int>(n);
    for(auto i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    
    auto r1 = vector<int>(n, -1);
    auto r2 = vector<int>(n, -1);

    for(auto i = 0; i < n; ++i)
    {
        int a = minFactor[A[i]];
        int b = A[i];
        while(b % a == 0) b /= a;
        if(a > 1 && b > 1)
            r1[i] = a, r2[i] = b;
    }

    for(auto i = 0; i < n; ++i)
        printf("%d ", r1[i]);
    printf("\n");
    for(auto i = 0; i < n; ++i)
        printf("%d ", r2[i]);    
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
