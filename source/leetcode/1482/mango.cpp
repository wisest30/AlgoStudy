class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 0, right = 1e9, mid = 0;
        int minDay = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if( isPossibleDay(bloomDay, m, k, mid)){
                minDay = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return  minDay;
    }
private:
    int isPossibleDay(vector<int>& bloomDay, int m, int k, int day){
        int n_bouque = 0;
        int count = 0;
        for(int i =0 ; i< bloomDay.size(); i++){
            if(bloomDay[i] <= day)
                count++;
            else
                count = 0;
            if( count == k){
                count = 0;
                n_bouque++;
                if( n_bouque == m)
                    return true;
            }
        }
        
        return false;
    }
};
