class CountIntervals {
public:
    set<pair<int, int>> s;
    int cnt;
    
    CountIntervals() : cnt(0) {}
    
    void add(int l, int r) {
        r++;
                       
        auto p = s.lower_bound(make_pair(l, 0));
        if(p != s.begin() && l < prev(p)->second)
            p = prev(p);
        
        vector<pair<int, int>> removes;
        for(; p != s.end() && r > p->first; ++p) {            
            l = min(l, p->first), r = max(r, p->second);
            removes.push_back(*p);
        }
        
        for(auto& pr : removes)
            s.erase(pr), cnt -= pr.second - pr.first;
        
        cnt += r - l;
        s.insert({l, r});
    }
    
    int count() { return cnt; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
