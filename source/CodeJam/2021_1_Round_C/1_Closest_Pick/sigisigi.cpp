
#include <bits/stdc++.h>
using namespace std;


void sol(){
    vector<int> range;
    vector<int> range_half;
    vector<int> inp;
    int N,K;
    int t;
    int st;
    cin>>N>>K;
    for(int i=0; i<N;i++){
        cin>>t;
        inp.push_back(t);
    }
    sort(inp.begin(),inp.end());
    st=inp[0]+1;
    range_half.push_back(inp[0]-1);
    for(int i=1; i<N;i++){
        if(inp[i]>st){
            range.push_back(inp[i]-st);
            range_half.push_back((inp[i]-st+1)/2);
        }
        st=inp[i]+1;
    }
    range_half.push_back(K-inp[N-1]);
    range.push_back(0);
    
    sort(range.rbegin(),range.rend());
    sort(range_half.rbegin(),range_half.rend());
    
    int MAX=max(range_half[0]+range_half[1],range[0]);
    double a= 1.0*MAX/K;
    cout << a << endl;
}

int main(){
    int TC;
    cin>>TC;
    for(int i=0; i<TC;i++){
    cout<<"Case #"<<i+1<<": ";   
    sol();
    }
    
    
}
