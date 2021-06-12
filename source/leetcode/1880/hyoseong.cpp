class Solution {
public:
    int get_num(string s) {
        for(auto& c : s)
            c = c - 'a' + '0';
        return stoi(s);
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return get_num(firstWord) + get_num(secondWord) == get_num(targetWord);
    }
};
