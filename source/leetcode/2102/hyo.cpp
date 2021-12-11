class SORTracker {
public:
    set<pair<int, string>> S;
    set<pair<int, string>>::iterator it;
    SORTracker() : it(S.begin()) {}
    
    void add(string name, int score) {
        auto p = make_pair(-score, name);
        if(it == S.end()) {
            S.insert(p);
            it = prev(S.end());
        } else {
            auto old = *it;
            S.insert(p);
            it = S.find(old);
            if(p < old)
                --it;
        }
    }
    
    string get() {
        return (it++)->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
