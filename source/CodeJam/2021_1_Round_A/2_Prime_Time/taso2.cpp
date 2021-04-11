#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(long long int sum, long long int l);
vector<int> arr;
vector<long long int> cnts;

long long int solve() {
    long long int sum = 0;
    for (int i=0; i<arr.size(); i++)
        sum += (long long int)arr[i] * cnts[i];
    for (long long int l=sum-1; max(sum-499*60, 1ll)<=l; l--) {
        if(check(sum, l))
            return l;
    }
    return 0;
}

bool check(long long int sum, long long int l) {
    long long int it = l;
    long long int rSum = 0;
    for (int i=0; i<arr.size(); i++) {
        int n = 0;
        while (it % arr[i] == 0) {
            it /= arr[i];
            n++;
        }
        if (cnts[i] < n)
            return false;
        rSum += (long long int)arr[i] * n;
    }
    if (it != 1)
        return false;
    return l + rSum == sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long int T, M, P, N;
    cin >> T;
    for (int i=0; i<T; i++) {
        arr.clear();
        cnts.clear();
        cin >> M;
        for (int j=0; j<M; j++) {
            cin >> P >> N;
            arr.push_back(P);
            cnts.push_back(N);
        }
        cout << "Case #" << (i+1) << ": " << solve() << endl;
    }
}