#include <bits/stdc++.h>
using namespace std;

vector<int> masks, graph;

int bfs(int src, int dest){
  bool vis[26] = {0,};
  queue<int> q;

  for(int node = 0; node< 26; ++node){
    if(src & (1 << node)) q.push(node), vis[node] = true;
  }

  int dist = -1;
  while(!q.empty()){
    int sz = q.size();
    ++dist;
    while(sz--){
      int cur = q.front();
      if(dest & (1 << cur)) return dist + 2;
      q.pop();
      for(int nxt = 0; nxt < 26; ++nxt){
        if(!vis[nxt] && graph[cur] & (1 << nxt)) vis[nxt] = true, q.push(nxt);
      }
    }
  }
  return -1;
}

void solve(int testNum){
  int n, qn, src, dest;
  string s;
  cin >> n >> qn;

  masks.clear(), graph.clear();
  masks.resize(n), graph.resize(26);
  
  for(int &mask: masks){
    cin >> s;
    for(char c: s) mask |= (1 << (c - 'A'));
  }

  for(int mask: masks){
    for(int i = 0; i < 26; ++i){
      if(mask & (1 << i)) graph[i] |= mask;
    }
  }

  cout << "Case #" << testNum << ": ";
  for(int i = 0; i< qn; ++i){
    cin >> src >> dest, --src, --dest;
    cout << bfs(masks[src], masks[dest]) << " ";
  }
  cout << "\n";

  return;
}

int main(){
  int T;
  cin >> T;
    for(int t = 1; t<= T; ++t){
      solve(t);
    }
  return 0;
}