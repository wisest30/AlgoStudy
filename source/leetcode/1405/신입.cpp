class Solution {
public:
    string mk_ans(int mx, int mid, int mn, char mx_ch, char mid_ch, char mn_ch, int mx_long, int mid_long, int mn_long)
    {
        if(mx < mid) return mk_ans(mid, mx, mn, mid_ch, mx_ch, mn_ch, mid_long, mx_long, mn_long);
        if(mid < mn) return mk_ans(mx, mn, mid, mx_ch, mn_ch, mid_ch, mx_long, mn_long, mid_long);

        if(mx_long  == 2)
        {
            if(mid == 0) return "";
            else return mid_ch + mk_ans(mx, mid - 1, mn, mx_ch, mid_ch, mn_ch, 0, 1, 0);
        }
        if(mx == 0) return "";
        return mx_ch + mk_ans(mx - 1, mid, mn, mx_ch, mid_ch, mn_ch, mx_long + 1, 0, 0);
    }
    
    string longestDiverseString(int a, int b, int c) {
        return mk_ans(a, b, c, 'a', 'b', 'c', 0, 0, 0);
    }
};
