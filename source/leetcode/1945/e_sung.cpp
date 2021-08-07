class Solution {
public:
    int sum(string& trans, int k){
        int temp_sum;
        for(int i = 0; i < k; i++){
            int number = atoi(trans.c_str());
            temp_sum = 0;
            for(int j = 0; j < trans.size(); j++){
                temp_sum += number % 10;
                number /= 10;
            }
            trans = to_string(temp_sum);
            //cout << " trans " << trans << endl;
            //cout << " temp_sum " << temp_sum << endl;
        }
        return temp_sum;
    }

    int changeString(string& before, string& after){
        int tmp = 0;
        int res = 0;
        for(int i = 0; i < before.size(); i++){
            tmp = before[i] - 'a' + 1;
            //cout << " tmp " << tmp << endl;
            if(tmp > 9){
                after += to_string(tmp / 10);
                res += tmp / 10;
                after += to_string(tmp % 10);
                res += tmp % 10;
            }
            else{
                after += to_string(tmp);
                res += tmp;
            }
            //cout << " after [" << i << "] " << after << endl;
        }
        return res;
    }

    int getLucky(string s, int k) {
        string changed;
        int changed_num = changeString(s, changed);
        changed = to_string(changed_num);
        //cout << " changed " << changed << endl;
        if(k == 1)
            return changed_num;
        else
            return sum(changed, k - 1);
    }
};
