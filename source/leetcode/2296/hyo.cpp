class TextEditor {
public:
    list<char> L;
    list<char>::iterator iter;
    
    TextEditor() : iter(L.begin()) {}
    
    void addText(string text) { 
        for(auto c : text)
            L.insert(iter, c);
    }
    
    int deleteText(int k) {
        int ret = 0;

        while(k-- && iter != L.begin())
            iter = L.erase(--iter), ++ret;

        return ret;
    }
    
    string cursorLeft(int k) {
        while(k-- && iter != L.begin())
            --iter;
        
        return get_left(10);
    }
    
    string cursorRight(int k) {
        while(k-- && iter != L.end())
            ++iter;
    
        return get_left(10);
    }
    
    string get_left(int k) {
        string ret;
        auto i = iter;
        while(k-- && i != L.begin())
            ret.push_back(*--i);
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
