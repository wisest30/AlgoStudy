#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        int num = 0;
        while(iss >> word){
            num++;
            if( word.find(searchWord) == 0)
                return num;
        }
        return -1;
    }
};
