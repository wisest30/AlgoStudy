class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string ret;
        int is_conti = 0;
        for(int i = 0; i < num.size(); i++){
            char left = num[i];
            char right = change[num[i] - '0'] + '0';
            if(left > right){
                if(is_conti == 0){
                    ret += left;
                    //cout << "left > right 1: " << ret << endl;
                }
                else{
                    ret += num.substr(i);
                    //cout << "left > right 2: " << ret << endl;
                    break;
                }
            }
            else if(left == right){
                if(is_conti == 0){
                   ret += right;
                   //cout << "left = right 1: " << ret << endl;
                }
                else if(is_conti == i){
                    is_conti = i + 1;
                    ret += right;
                    //cout << "left = right 2: " << ret << endl;
                }
            }
            else{
                if(is_conti == 0 || is_conti == i){
                    ret += right;
                    is_conti = i + 1;
                    //cout << "left < right 1: " << ret << endl;
                }
                else{
                    ret += num.substr(i);
                    //cout << "left < right 2: " << ret << endl;
                    break;
                }
            }
        }
       return ret;
    }
};
