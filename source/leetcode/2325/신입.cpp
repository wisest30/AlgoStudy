class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> mapping;
        char ch = 'a';
        
        for(int i=0;i<key.size();i++)
        {
            if(key[i] == ' ') continue;
            if(mapping.find(key[i]) == mapping.end()) mapping[key[i]] = ch++;
        }
        
        for(int i=0;i<message.size();i++) 
        {
            if(message[i] == ' ') continue;
            message[i] = mapping[message[i]];
        }
        return message;
    }
};
