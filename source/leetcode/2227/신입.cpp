class Encrypter {
public:
    map<char, string> encryptMap;
    map<string, int> decryptMap;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        
        for(int i=0;i<n;i++) encryptMap[keys[i]] = values[i];
        for(string &str : dictionary) decryptMap[encrypt(str)]++;
    }
    
    string encrypt(string word1) {
        string ret;
        
        for(char ch : word1) 
        {
            if(encryptMap.count(ch)) ret += encryptMap[ch];
            else return word1;
        }
        return ret;
    }
    
    int decrypt(string word2) {
        return decryptMap[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
