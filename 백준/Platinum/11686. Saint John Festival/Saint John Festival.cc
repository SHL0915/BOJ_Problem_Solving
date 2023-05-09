#define _GLIBCXX_FILESYSTEM

#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'

// def

using lli = long long int;


using pii = pair<int, int>;
using pll = pair<lli, lli>;

#define X first
#define Y second

#define rep(I, S, E) for(int I = (S); I < (E); I++)
#define repq(I, S, E) for(int I = (S); I <= (E); I++)

#define pb push_back
#define epb emplace_back

#define ALL(V) V.begin(), V.end()

pll operator+(pll a, pll b) {
    return { a.X + b.X, a.Y + b.Y };
}
pll operator-(pll a, pll b) {
    return { a.X - b.X, a.Y - b.Y };
}

lli operator*(pll a, pll b) {
    return a.X * b.Y - a.Y * b.X;
}
lli CCW(pll a, pll b, pll c) {
    return a * b + b * c + c * a;
}

ostream& operator<<(ostream& out, pii x) {
    out << "(" << x.X << ", " << x.Y << ")";
    return out;
}

// def end

vector<pll> p;
vector<pll> cvx;

bool Comp(pll a, pll b) {
    if (a * b == 0)
        return a < b;
    return a * b > 0;
}

void ConvexHull() {
    int n = p.size();
    sort(ALL(p));

    rep(i, 1, n)
        p[i] = p[i] - p[0];

    sort(p.begin() + 1, p.end(), Comp);
    rep(i, 1, n)
        p[i] = p[i] + p[0];

    cvx.pb(p[0]);
    rep(i, 1, n) {
        while (cvx.size() >= 2 && CCW(cvx[cvx.size() - 2], cvx.back(), p[i]) <= 0)
            cvx.pop_back();
        cvx.pb(p[i]);
    }
}

int main() {
    fastio;

    int l;
    cin >> l;
    p.resize(l);
    rep(i, 0, l) {
        cin >> p[i].X >> p[i].Y;
    }

    ConvexHull();
    rep(i, 1, cvx.size())
        cvx[i] = cvx[i] - cvx[0];
    sort(cvx.begin() + 1, cvx.end(), Comp);
    rep(i, 1, cvx.size())
        cvx[i] = cvx[i] + cvx[0];

    int res = 0;

    int q;
    cin >> q;
    while (q--) {
        pll k;
        cin >> k.X >> k.Y;

        int lo = 1, hi = (int)cvx.size() - 2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (CCW(cvx[mid], cvx[0], k) <= 0)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if (hi == 0)
            continue;

        vector<pll> r = { cvx[0], cvx[hi], cvx[hi + 1] };

        bool f = true;
        rep(i, 0, 3) {
            f &= (CCW(r[i], r[(i + 1) % 3], k) >= 0);
        }
        res += f;
    }
    cout << res;

    return 0;
}