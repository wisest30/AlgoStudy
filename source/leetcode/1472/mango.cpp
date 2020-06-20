class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        idx = 0;
        history.push_back(homepage);
    }
    
    void visit(string url) {
        history.erase(history.begin()+idx+1, history.end());
        idx++;
        history.push_back(url);
    }
    
    string back(int steps) {
        while(steps && idx){
            idx--;
            steps--;
        }
        return history[idx];
    }
    
    string forward(int steps) {
        while(steps && idx + 1< history.size()){
            idx++;
            steps--;
        }
        return history[idx];
    }
private:
    vector<string> history;
    int idx;
};
