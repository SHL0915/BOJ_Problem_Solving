#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

int f(int now, vector<int> &v) {
    if (now == -1) return 0;
    
    vector<int> nxt;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] & (1 << now)) nxt.push_back(v[i]);
    }
    
    if (nxt.size() >= K) return (1 << now) + f(now - 1, nxt);
    else return f(now - 1, v);
}

void solve() {
    cin >> N >> K;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    cout << f(21, v);
    
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