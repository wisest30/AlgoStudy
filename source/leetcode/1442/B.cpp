class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            int left = 0;
            for(int j = i; j< arr.size(); j++){
                left ^= arr[j];
                int right = 0;
                for(int k= j +1; k < arr.size(); k++){
                    right ^= arr[k];
                    if( left == right)
                        count++;
                }
            }
        }
        return count;
    }
};
