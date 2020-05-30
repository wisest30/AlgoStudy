#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<string, int> PSI;
bool compare(const PSI& lhs, const PSI& rhs){
    if( lhs.first.size() != rhs.first.size())
        return lhs.first.size() < rhs.first.size();
    return lhs.second < rhs.second;
}

class Solution {
    
    
public:
    string arrangeWords(string text) {
        vector<PSI> words;
        istringstream is(text);
        string word, ordered_sentence;
        int order = 0;
        while(is >> word){
            if( !order )
                word[0] = word[0] - 'A' + 'a';
            words.push_back(PSI(word, order++));
        }
        
        
        sort(words.begin(), words.end(), compare);
        locale loc;
        for(int i = 0; i < words.size(); i++){
            if( i )
                ordered_sentence += " ";
            string word = words[i].first;
            if( i == 0)
                word[0] = word[0] - 'a' + 'A';
            ordered_sentence += word;
        }
        
        
        return ordered_sentence;
    }
};
