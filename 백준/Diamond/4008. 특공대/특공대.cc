#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e15;

struct line {
    ll a, b;
    double x;

    line(ll a, ll b, double x) : a(a), b(b), x(x) {};

    ll f(ll x) {
        return a * x + b;
    }
};

ll N, A, B, C;
int ptr;
ll arr[1000005], psum[1000005], dp[1000005];
vector<line> L;

ll slope(int i) {
    return -2 * A * psum[i];
}

ll intercept(int i) {
    return A * psum[i] * psum[i] - B * psum[i] + dp[i];
}

ll f(int i) {
    return A * psum[i] * psum[i] + B * psum[i] + C;
}

double intersect(line &a, line &b) {
    return (double) (a.b - b.b) / (b.a - a.a);
}

void add_line(ll a, ll b) {
    line l(a, b, -INF);
    if (L.size() == 0) {
        L.push_back(l);
        return;
    }

    while(L.size()) {
        line t = L.back();
        double x = intersect(t, l);
        if(x <= t.x) L.pop_back();
        else break;
    }

    l.x = intersect(l, L.back());
    L.push_back(l);

    return;
}

ll query(ll x) {
    while (ptr < L.size() - 1 && L[ptr + 1].x <= x) ptr++;

    return L[ptr].f(x);
}


void solve() {
    cin >> N >> A >> B >> C;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }

    dp[1] = f(1);
    add_line(slope(1), intercept(1));

    for (int i = 2; i <= N; i++) {
        dp[i] = max(f(i), query(psum[i]) + f(i));
        add_line(slope(i), intercept(i));
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