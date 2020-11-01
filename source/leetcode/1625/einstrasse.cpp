#include <set>
#include <string>
using namespace std;
string oper1(string s, int a) {
    for (int i=1; i < s.length(); i+=2) {
        char& c = s[i];
        c -= '0';
        c += a;
        c %= 10;
        c += '0';
    }
    return s;
}
string oper2(string s, int b) {
    string ret = "";
    int l = s.length();
    for (int i=0; i< l; i++) {
        ret += s[(i-b+l)%l];
    }
    return ret;
}
void dfs(set<string>& visit, string s, int a, int b) {
    string n1 = oper1(s, a);
    string n2 = oper2(s, b);
    if (visit.find(n1) == visit.end()) {
        visit.insert(n1);
        dfs(visit, n1, a, b);
    }
    if (visit.find(n2) == visit.end()) {
        visit.insert(n2);
        dfs(visit, n2, a, b);
    }
}
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> visit;
        visit.insert(s);
        dfs(visit, s, a, b);
        return *visit.begin();
    }
};