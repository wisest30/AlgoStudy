#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<vector<int>> favoriteCompaniesAsNum;
        map<string, int> companyNum;
        vector<int> notSubsetPerson;
        for(auto companies : favoriteCompanies){
            for(auto company: companies){
                if(companyNum.count(company))
                    continue;
                companyNum[company] = companyNum.size();
            }
            vector<int> companiesAsNum;
            for(auto company : companies)
                companiesAsNum.push_back(companyNum[company]);
            sort(companiesAsNum.begin(), companiesAsNum.end());
            favoriteCompaniesAsNum.push_back(companiesAsNum);
        }
        
        int numPeople = favoriteCompaniesAsNum.size();
        for(int i = 0; i < numPeople; i++){
            bool isSubSet = false;
            for(int j = 0; j < numPeople && !isSubSet; j++){
                if( i == j || favoriteCompaniesAsNum[i].size() > favoriteCompaniesAsNum[j].size())
                    continue;
                int idx = 0;
                for(int k = 0; k < favoriteCompaniesAsNum[j].size(); k++){
                    if( favoriteCompaniesAsNum[i][idx] == favoriteCompaniesAsNum[j][k])
                        idx++;
                    if( idx == favoriteCompaniesAsNum[i].size())
                        break;
                }
                if( idx == favoriteCompaniesAsNum[i].size())
                    isSubSet = true;
            }
            
            if( !isSubSet )
                notSubsetPerson.push_back(i);
            
        }
        return notSubsetPerson;
    }
};
