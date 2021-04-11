#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> arrs;

int compare(vector<int>& a, vector<int>& b, int len) {
    if (a.size() < len) {
        return 1;
    }
    if (b.size() < len) {
        return -1;
    }
    for (int i=0; i<len; i++) {
        if (a[i] > b[i])
            return -1;
        else if (a[i] < b[i])
            return 1;
    }
    return 0;
}

int incr(vector<int>& arr, int from) {
    bool isAllNine = true;
    for (int i=from; i<arr.size(); i++) {
        if (arr[i] != 9) {
            isAllNine = false;
            break;
        }
    }
    if (isAllNine) {
        for (int i=from; i<arr.size(); i++)
            arr[i] = 0;
        arr.push_back(0);
        return 1;
    } else {
        arr[arr.size()-1] += 1;
        for (int i=arr.size()-1; from <= i; i--) {
            if (9 < arr[i]) {
                arr[i] = 0;
                arr[i-1] += 1;
            }
        }
        return 0;
    }
}


int solve() {
    int sol = 0;
    int compRes;
    for (int i=1; i<arrs.size(); i++) {
        int from = arrs[i].size();
        while ((compRes=compare(arrs[i-1], arrs[i], max(arrs[i-1].size(), arrs[i].size())))<=0) {
            int compRes2 = compare(arrs[i-1], arrs[i], arrs[i].size());
            if (compRes2 == 0) {
                if (arrs[i-1].size() == arrs[i].size()) { // exactly same
                    sol += incr(arrs[i], from);
                    break;
                } else { // len(i-1) > len(i)
                    arrs[i].push_back(arrs[i-1][arrs[i].size()]);
                }
            } else { // compRes < 0 => arrs[i] < arrs[i-1] (in len)
                arrs[i].push_back(0);
            }
            sol += 1;
        }
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, tmp;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N;
        arrs = vector<vector<int>>(N);
        for (int j=0; j<N; j++) {
            cin >> tmp;
            while (tmp) {
                arrs[j].push_back(tmp%10);
                tmp = tmp/10;
            }
            reverse(arrs[j].begin(), arrs[j].end());
        }
        cout << "Case #" << (i+1) << ": " << solve() << endl;
    }
}