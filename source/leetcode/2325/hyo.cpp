class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> m;
        char cur = 'a';
        for(auto c : key)
            if(c != ' ' && !m.count(c) && c <= 'z')
                m[c] = cur++;
        
        for(auto& c : message)
            if(c != ' ')
                c = m[c];
        
        return message;
    }
};
