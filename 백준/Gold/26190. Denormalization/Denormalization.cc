#include <bits/stdc++.h>

#define double long double
using namespace std;
using ll = long long;
using pii = pair<int, int>;
double err = 5e-3;

int N;
double arr[10001];

void solve() {
    cin >> N;
    double m = 1.0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        m = min(m, arr[i]);
    }

    for (int i = 0; i < N; i++) arr[i] /= m;
    // all arr[i] >= 1.0

    double eps = 1e9;
    vector<int> cand;
    for (int i = 1; i <= 10000; i++) {
        double cEps = 0.0;
        vector<int> v;
        for (int j = 0; j < N; j++) {
            double now = arr[j]  * (double) (i);
            double nnow = round(now);
            v.emplace_back((int)nnow);
            cEps = max(cEps, abs(nnow - now));
        }
        if(cEps < eps) {
            eps = cEps;
            cand = v;
        }

    }

    for(auto &x: cand) cout << x << '\n';
}

int main(void) {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}