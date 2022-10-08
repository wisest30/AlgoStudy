class LUPrefix {
public:
    set<int> s;
    LUPrefix(int n) {
        for(auto i = 0; i < n + 1; ++i) s.insert(i+1);
    }
    
    void upload(int video) {
        s.erase(video);
    }
    
    int longest() {
        return (*s.begin()) - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
