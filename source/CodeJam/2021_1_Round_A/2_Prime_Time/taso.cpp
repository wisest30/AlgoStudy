#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(int i, int curSum, int curProd);
vector<int> arr;
vector<int> cnts;

int solve() {
    int sum = 0;
    for (int i=0; i<arr.size(); i++)
        sum += arr[i] * cnts[i];
    return dfs(0, sum, 1);
}

int dfs(int i, int curSum, int curProd) {
    if (arr.size() == i) {
        if (curSum == curProd)
            return curProd;
        else
            return 0;
    }
    int res = dfs(i+1, curSum, curProd); // skip this index
    for (int j=1; j<=cnts[i]; j++) {
        curSum -= arr[i];
        curProd *= arr[i];
        if (curSum < curProd)
            break;
        res = max(res, dfs(i+1, curSum, curProd));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, M, P, N;
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