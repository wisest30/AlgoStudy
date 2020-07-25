typedef long double ld;

class Solution {
public:
    ld calc(vector<vector<int>>& positions, ld x, ld y)
    {
        ld res = 0;

        for (auto& position : positions)
        {
            ld dx = (ld)position[0] - x;
            ld dy = (ld)position[1] - y;
            res += sqrtl(dx* dx + dy * dy);
        }

        return res;
    }

    double getMinDistSum(vector<vector<int>>& positions)
    {
        ld x = 50;
        ld y = 50;

        ld before = calc(positions, x, y);

        while (true)
        {
            ld lo = 0, hi = 100;

            for (int i = 0; i < 100; i++)
            {
                ld p = (lo * 2 + hi) / 3, q = (lo + 2 * hi) / 3;
                if (calc(positions, x, p) <= calc(positions, x, q)) hi = q;
                else lo = p;
            }

            y = lo;

            lo = 0, hi = 100;

            for (int i = 0; i < 100; i++)
            {
                ld p = (lo * 2 + hi) / 3, q = (lo + 2 * hi) / 3;
                if (calc(positions, p, y) <= calc(positions, q, y)) hi = q;
                else lo = p;
            }

            x = lo;

            ld cur = calc(positions, x, y);

            if (cur - before > -1e-6 && cur - before < 1e-6) break;

            before = cur;
        }

        return before;
    }
};
