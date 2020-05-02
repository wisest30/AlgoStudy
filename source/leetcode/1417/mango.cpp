#include <iostream>
using namespace std;
class Solution {
public:
    string reformat(string s) {
        string letter, digit;
        for(char ch: s){
            if( ch >= '0' && ch <= '9')
                letter += ch;
            else
                digit += ch;
        }
        
        if(max(letter.size(), digit.size()) - min(letter.size(), digit.size()) >= 2){
            return "";
        }
        if( letter.size() > digit.size())
            return combineTwoStr(letter, digit);
        return combineTwoStr(digit, letter);
        
    }
private:
    string combineTwoStr(string s, string t){
        string result;
        for(int i = 0; i < s.size(); i++){
            result += s[i];
            if( i == s.size() - 1 && t.size() < s.size())
                break;
            result += t[i];
        }
        return result;
    }
};
