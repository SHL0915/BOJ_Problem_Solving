#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 1e10;

struct line { // f(x) = ax + b, x >= s
    ll a, b;
    double s;

    line(ll a = 0, ll b = 0, double s = 0) : a(a), b(b), s(s) {};

    ll f(ll x) {
        return a * x + b;
    }
};

int N;
ll A[100005], B[100005];
ll dp[100005];
int ptr;
vector<line> arr;

double intersect(line &a, line &b) {
    return (double) (b.b - a.b) / (a.a - b.a);
}

void add_Line(ll a, ll b) {
    line L(a, b, -INF);

    if (arr.size() == 0) {
        arr.push_back(L);
        return;
    }

    while (arr.size()) {
        line t = arr.back();
        double x = intersect(t, L);

        if (x <= t.s) arr.pop_back();
        else break;
    }

    L.s = intersect(arr.back(), L);
    arr.push_back(L);

    return;
}

ll query(ll x) {
    while (ptr < arr.size() - 1 && arr[ptr + 1].s < x) ptr++;
    return arr[ptr].f(x);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    dp[0] = 0;
    add_Line(B[0], dp[0]);

    for (int i = 1; i < N; i++) {
        dp[i] = query(A[i]);
        add_Line(B[i], dp[i]);
    }

    cout << dp[N - 1];
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