#include <map>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> folderNames;
        map<string, int> wordMap;
        for(auto name : names){
            if(wordMap.count(name)){
                int k = wordMap[name];
                while(wordMap.count(name + "(" + to_string(k) + ")")){
                    k++;
                    wordMap[name]++;
                }
                wordMap[name]++;
                name += "(" + to_string(k) + ")";
            }
            wordMap[name] = 1;
            folderNames.push_back(name);
        }
        return folderNames;
    }
};
