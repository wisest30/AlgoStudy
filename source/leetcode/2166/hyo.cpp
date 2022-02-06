class Bitset {
private:
    string s, r;
    int cnt;
    bool f;
    char get(int idx) { return f ? r[idx] : s[idx]; }
    void set(int idx, char val) {
        if(get(idx) != val) {
            swap(s[idx], r[idx]);
            if(s[idx] == '1') cnt++;
            else cnt--;
        }
    }
    
public:
    Bitset(int size) : s(size, '0'), r(size, '1'), cnt(0), f(false) {}
    void fix(int idx) { set(idx, '1'); }
    void unfix(int idx) { set(idx, '0'); }
    void flip() { f ^= 1; }
    bool all() { return count() == s.size(); }
    bool one() { return count() > 0; }
    int count() { return f ? (int)s.size() - cnt : cnt; }    
    string toString() { return f ? r : s; }
};
