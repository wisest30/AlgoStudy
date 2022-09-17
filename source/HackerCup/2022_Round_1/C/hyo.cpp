#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

double EPSILON = 1e-13;
struct my_vector {
    const double PI = 2.0 * acos(0.0);
    double x, y;
    explicit my_vector(double x = 0, double y = 0)
    : x(x), y(y) {}
    my_vector& operator = (const my_vector& other) { x = other.x, y = other.y; return *this; }
    bool operator == (const my_vector& other) const { return x == other.x && y == other.y; }
    bool operator != (const my_vector& other) const { return x != other.x || y == other.y; }
    bool operator < (const my_vector& other) const { return x != other.x ? x < other.x : y < other.y; }
    my_vector operator + (const my_vector& other) const { return my_vector(x + other.x, y + other.y); }
    my_vector operator += (const my_vector& other) { x += other.x, y += other.y; return *this; }
    my_vector operator - (const my_vector& other) const { return my_vector(x - other.x, y - other.y); }
    my_vector operator -() const { return my_vector(-x, -y); }
    my_vector operator -= (const my_vector& other) { x -= other.x, y -= other.y; return *this; }
    my_vector operator * (double r) const { return my_vector(x * r, y * r); }
    my_vector operator *= (double r) { x *= r, y *= r; return *this; }
    double norm() const { return hypot(x, y); }
    my_vector normalize() const {
        assert(norm() != 0);
        assert(!is_null());
        return my_vector(x / norm(), y / norm());
    }
    double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
    double dot(const my_vector& other) const { return x * other.x + y * other.y; }
    double cross(const my_vector& other) const { return x * other.y - other.x * y; }
    my_vector project(const my_vector& other) const { auto r = other.normalize(); return r * r.dot(*this); }
    void print() const { cout << x << " " << y << endl; }
    bool is_null() const { return x == numeric_limits<double>::min() && y == numeric_limits<double>::min(); }
    void set_null() { x = numeric_limits<double>::min(), y = numeric_limits<double>::min(); }
};

my_vector null_vec = my_vector(numeric_limits<double>::min(), numeric_limits<double>::min());

// + : ccw, 0 : paralle, - : cw
double ccw(my_vector a, my_vector b)
{ return a.cross(b); }

// center : p
double ccw(my_vector p, my_vector a, my_vector b)
{ return ccw(a-p, b-p); }

// line1 : a, b     line2 : c, d
// ret1 : false if parallel, ret2 : intersection point
my_vector lineIntersection(my_vector a, my_vector b, my_vector c, my_vector d)
{
    double det = (b - a).cross(d - c);
    if(fabs(det) < EPSILON) return null_vec;
    auto ret = a + (b - a) * ((c - a).cross(d - c) / det);
    return ret;
}

my_vector parallelSegments(my_vector a, my_vector b, my_vector c, my_vector d)
{
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);

    if(ccw(a, b, c) != 0 || b < c || d < a) return null_vec;
    if(a < c) return c;
    else return a;
}

// p, a, b have to be in a line.
// rectangle : a to b
bool inBoundingRectangle(my_vector p, my_vector a, my_vector b) {
    if(b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}

my_vector segmentIntersection(my_vector a, my_vector b, my_vector c, my_vector d)
{
    auto p = lineIntersection(a, b, c, d);
    if(p.is_null())
        return parallelSegments(a, b, c, d);
    
    if(inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d))
        return p;
    else
        return null_vec;
}

my_vector perendicularFoot(my_vector p, my_vector a, my_vector b)
{ return a + (p - a).project(b - a); }

double pointToLine(my_vector p, my_vector a, my_vector b)
{ return (p - perendicularFoot(p, a, b)).norm(); }

vector<my_vector> graham_scan(const vector<my_vector>& A) {
    const double PI = 2.0 * acos(0.0);

    auto B = A;
    B.erase(unique(B.begin(), B.end()), B.end());
    if(B.size() <= 2) return B;

    auto min_vector_idx = 0;
    for(auto i = 0; i < B.size(); ++i)
        if(B[i].x < B[min_vector_idx].x)
            min_vector_idx = i;
    
    swap(B[0], B[min_vector_idx]);
    sort(B.begin() + 1, B.end(), [&](auto& x, auto& y) {
            double xx = (x - B[0]).polar();
            double yy = (y - B[0]).polar();
            if(xx < PI && yy > PI) return false;
            if(xx > PI && yy < PI) return true;
            if(xx == yy)
                return x < y;
            return xx < yy;
        }
    );

    auto ret = vector<my_vector>{B[0], B[1]};
    for(auto i = 2; i < B.size(); ++i) {
        int last = (int)ret.size() - 1;
        int llast = last - 1;
        while(ret.size() >= 2 && (ret[last] - ret[llast]).cross(B[i] - ret[last]) <= 0) {
            ret.pop_back();
            last--, llast--;
        }
        ret.push_back(B[i]);
    }

    return ret;
}

void solve(int TestCase) {
    ll n, k, d;
    cin >> n >> k >> d;

    vector<my_vector> A;
    for(auto i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        A.emplace_back(x, y);
    }

    ll sx = A[0].x, sy = A[0].y, ex = A.back().x, ey = A.back().y;
    int s = -1, e = -1;
    A = graham_scan(A);
    n = A.size();
    for(auto i = 0; i < n; ++i) {
        if(A[i].x == sx && A[i].y == sy) s = i;
        if(A[i].x == ex && A[i].y == ey) e = i;
    }
    assert(s >= 0 && e >= 0);

    vector<ll> D(n, INT64_MAX);
    priority_queue<pair<ll, ll>> q;
    q.push({0, s});
    while(!q.empty()) {
        auto [di, i] = q.top();
        q.pop();
        di = -di;

        if(D[i] != INT64_MAX) continue;
        D[i] = di;
        if(i == e) break;

        ll xi = A[i].x, yi = A[i].y;
        for(auto j = 0; j < n; ++j) {
            if(i == j || D[j] != INT64_MAX) continue;
            ll xj = A[j].x, yj = A[j].y;
            ll dij = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
            if(dij > d * d) continue;
            dij = max(dij, k);
            q.push({-(di + dij), j});
        }
    }

    auto ans = D[e] == INT64_MAX ? -1 : D[e];
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}