class BrowserHistory {
public:
    vector<string> hs;
    int cur;
    BrowserHistory(string h) {
        hs.clear();
        hs.push_back(h);
        cur = 0;
    }
    
    void visit(string url) {
        hs.resize(cur+1);
        hs.push_back(url);
        cur++;
    }
    
    string back(int steps) {
        int r = cur;
        if(steps>r) cur -= r;
        else cur -= steps;
        return hs[cur];
    }
    
    string forward(int steps) {
        int r = hs.size()-1-cur;
        if(steps>r) cur += r;
        else cur += steps;
        return hs[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
