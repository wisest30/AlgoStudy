#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void maximizeColorSum(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> weight(n), degree(n), candidate;
        long long weight_sum = 0;
        
        for(int i = 0; i< n; i++){
            cin >> weight[i];
            weight_sum += weight[i];
        }
        
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            degree[u-1]++;
            degree[v-1]++;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < degree[i] - 1; j++){
                candidate.push_back(weight[i]);
            }
        }
        
        sort(candidate.begin(), candidate.end());
        reverse(candidate.begin(), candidate.end());
        
        long long colorset_sum = weight_sum;
        cout << colorset_sum << " ";
        
        for(int i = 0; i < n - 2; i++){
            colorset_sum += candidate[i];
            cout << colorset_sum << " ";
        }
        cout << "\n";
        
    }
    
}

int main(void){
//    freopen("input.txt","r",stdin);
    maximizeColorSum();
    
    return 0;
}
