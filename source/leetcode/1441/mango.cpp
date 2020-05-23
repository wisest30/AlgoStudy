class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> order;
        int num = 1;
        for(int i = 0; i < target.size(); i++){
            while( num < target[i]){
                order.push_back("Push");
                order.push_back("Pop");
                num += 1;
            }
            order.push_back("Push");
            num += 1;
        }
        return order;
    }
};
