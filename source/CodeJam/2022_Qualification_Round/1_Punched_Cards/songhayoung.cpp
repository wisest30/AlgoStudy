#include <bits/stdc++.h>
using namespace std;
void punch(int c) {
    cout<<"..";
    for(int i = 0 ; i < c - 1; i++) cout<<"+-";cout<<"+"<<endl;
    cout<<"..";
    for(int i = 0 ; i < c - 1; i++) cout<<"|.";cout<<"|"<<endl;
}
void plane(int r, int c) {
    for(int R = 0; R < r-1; R++) {
        for(int i = 0 ; i < c; i++) cout<<"+-";cout<<"+"<<endl;
        for(int i = 0 ; i < c; i++) cout<<"|.";cout<<"|"<<endl;
    }
    for(int i = 0 ; i < c; i++) cout<<"+-";cout<<"+"<<endl;
}
void solve(int r, int c) {
    punch(c);
    plane(r,c);
}

int main() {
    int tc;
    cin>>tc;
    for(int i = 1; i <= tc; i++) {
        int r, c;
        cin>>r>>c;
        cout<<"Case #"<<i<<":"<<endl;
        solve(r,c);
    }
    return 0;
}
