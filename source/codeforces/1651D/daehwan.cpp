#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n;
vector<vector<int>> v;
set<vector<int>> s;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};
map<vector<int>,vector<int>> ans;
queue<vector<int>> q;

void solve(int TestCase) {
    cin >> n;
    v   = vector<vector<int>>(n);
    s   = set<vector<int>>();
    ans = map<vector<int>,vector<int>>();
    q   = queue<vector<int>>();
    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        v[i].push_back(x);
        v[i].push_back(y);
        s.insert({x,y});
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            int x = v[i][0];
            int y = v[i][1];
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(s.count({nx,ny})) continue;
            ans[{x,y}] = {nx,ny};
            q.push({x,y});
            break;
        }
    }
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!s.count({nx,ny})) continue;
            if(ans.count({nx,ny})) continue;
            ans[{nx,ny}] = ans[{x,y}];
            q.push({nx,ny});
        }
    }
    for(int i=0; i<n; i++){
        int x = v[i][0];
        int y = v[i][1];
        int u = ans[{x,y}][0];
        int v = ans[{x,y}][1];
        cout << u << " " << v << endl;
    }

}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
