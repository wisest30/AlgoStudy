class TextEditor {
public:
    vector<char> leftStk;
    vector<char> rightStk;
    
    TextEditor() {
    }
    
    void addText(string text) {
        for(char ch : text) leftStk.push_back(ch);
    }
    
    int deleteText(int k) {
        int ret = 0;
        
        while(k && !leftStk.empty())
        {
            leftStk.pop_back();
            ret++;
            k--;
        }
        
        return ret;
    }
    
    string getOutput()
    {
        int n = leftStk.size();
        int outputLen = min(10, n);
        string output;
        
        for(int i=n-outputLen;i<n;i++) output += leftStk[i];
        
        return output;
    }
    
    string cursorLeft(int k) {
        while(k && !leftStk.empty())
        {
            rightStk.push_back(leftStk.back());
            leftStk.pop_back();
            k--;
        }
        
        return getOutput();    
    }
    
    string cursorRight(int k) {
        while(k && !rightStk.empty())
        {
            leftStk.push_back(rightStk.back());
            rightStk.pop_back();
            k--;
        }
        
        return getOutput();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
