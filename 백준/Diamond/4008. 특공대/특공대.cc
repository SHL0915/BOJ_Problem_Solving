#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e10;

struct line {
    ll a, b;
    double s;

    line(ll a = 0, ll b = 0, double c = 0) : a(a), b(b), s(c) {};

    ll f(ll x) {
        return a * x + b;
    }
};

ll N, A, B, C, K;
int ptr;
ll arr[1000005], psum[1000005];
ll dp[1000005];
vector<line> l;

double intersect(line &a, line &b) {
    return (double) (a.b - b.b) / (b.a - a.a);
}

void add_line(ll a, ll b) {
    line L(a, b, -INF);

    if (l.size() == 0) {
        l.push_back(L);
        return;
    }

    while (l.size()) {
        line t = l.back();
        double x = intersect(t, L);
        if (x <= t.s) l.pop_back();
        else break;
    }

    L.s = intersect(l.back(), L);
    l.push_back(L);

    return;
}

ll k_i(int i) {
    return -2 * A * psum[i];
}

ll m_i(int i) {
    return A * psum[i] * psum[i] - B * psum[i] + dp[i];
}

ll query(ll x) {
    while (ptr < l.size() - 1 && l[ptr + 1].s < x) ptr++;
    return l[ptr].f(x);
}

ll f(int i) {
    return A * psum[i] * psum[i] + B * psum[i] + C;
}

void solve() {
    cin >> N >> A >> B >> C;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }

    dp[1] = A * psum[1] * psum[1] + B * psum[1] + C;
    add_line(k_i(1), m_i(1));

    for (int i = 2; i <= N; i++) {
        dp[i] = max(f(i), query(psum[i]) + f(i));
        add_line(k_i(i), m_i(i));
    }

    cout << dp[N];
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}