class SmallestInfiniteSet {
public:
    int x;
    set<int> s;
    SmallestInfiniteSet() : x(1) {}
    int popSmallest() {
        if(!s.empty()) {
            auto ret = *s.begin();
            s.erase(ret);
            return ret;
        }
        
        return x++;
    }
    
    void addBack(int num) {
        if(num < x)
            s.insert(num);
    }
};
