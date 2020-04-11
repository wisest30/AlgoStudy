
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int res;
    vector<int> rat;
    void comb(vector<int> vec, int pos, int gt) {
        if(vec.size()==3) {
            if((rat[vec[0]]<rat[vec[1]]&&rat[vec[1]]<rat[vec[2]])||
                    (rat[vec[0]]>rat[vec[1]]&&rat[vec[1]]>rat[vec[2]])) {
                res++;
            }
            return;
        }

        for(int i=pos; i<rat.size(); i++) {
            if((gt==0&&rat[i]<prev_val)||
                    (gt==1&&rat[i]>prev_val)) {
                vec.push_back(i);
                comb(vec, i+1);
                vec.pop_back();
            }
        }
    }
    int numTeams(vector<int>& rating) {
        res = 0;
        rat = rating;
        vector<int> vec = vector<int>(0);
        comb(vec, 0, 0);
        comb(vec, 0, 1);

        return res;
    }
};

