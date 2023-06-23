#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

void f(vector<int> &v);

void solve() {
    cin >> N >> K;
    vector<int> v;
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    f(v);
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

void f(vector<int> &v) {
    cout << N << " ";
    if (v.size() == 0) cout << 1 << '\n' << 1 << '\n';
    else {
        if (v.front() == 1) {
            cout << K - 1 << '\n';
            for (int i = 1; i < v.size(); i++) cout << v[i] << " ";
            cout << '\n';
        } else {
            cout << K + 1 << '\n';
            cout << 1 << " ";
            for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
            cout << '\n';
        }
    }
    return;
}