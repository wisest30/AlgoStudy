#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    double getProbability(vector<int>& balls) {
        vector<int> firstBox, secondBox;
        firstBox.resize(balls.size());
        secondBox.resize(balls.size());
        double allNumber = 0, caseNumber = 0;
        dfs(0, balls, firstBox, secondBox, allNumber, caseNumber);
        return caseNumber / allNumber;
    }
private:
    double factorial(int n){
        double output = 1;
        for(int i = 2; i<= n; i++)
            output *= i;
        return output;
    }
    
    void dfs(int curIdx, vector<int>& balls, vector<int>& firstBox, vector<int>& secondBox, double & allNumber, double& caseNumber){
        if( curIdx == balls.size()){
            int firstBallSum = accumulate(firstBox.begin(), firstBox.end(), 0);
            int secondBallSum = accumulate(secondBox.begin(), secondBox.end(), 0);
            if( firstBallSum != secondBallSum)
                return ;
            double case1 = factorial(firstBallSum);
            for(int i = 0; i< firstBox.size(); i++)
                case1 /= factorial(firstBox[i]);
            double case2 = factorial(firstBallSum);
            for(int i = 0; i< secondBox.size(); i++)
                case2 /= factorial(secondBox[i]);
            allNumber += case1 * case2;
            int numUnique[2] = {0,};
            for(int i = 0; i< firstBox.size(); i++){
                if( firstBox[i])
                    numUnique[0]++;
            }
            for(int i = 0; i< secondBox.size(); i++){
                if( secondBox[i])
                    numUnique[1]++;
            }
            if( numUnique[0] == numUnique[1])
                caseNumber+= case1 * case2;
            return;
        }
        
        for(int i = 0 ; i <= balls[curIdx]; i++){
            firstBox[curIdx] = i;
            secondBox[curIdx] = balls[curIdx] - i;
            dfs(curIdx + 1, balls, firstBox, secondBox, allNumber, caseNumber);
        }
        
    }
};
