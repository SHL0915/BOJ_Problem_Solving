#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A, B, K;

void solve() {
    cin >> A >> B >> K;
    
    if (B % A) {
        cout << -1;
        return;
    }
    
    vector<ll> ans;
    ans.push_back(A), ans.push_back(B);
    
    vector<ll> v;
    ll val = B / A;
    
    for (int i = 2; i * i <= val; i++) {
        if (val % i) continue;
        v.push_back(i);
        if (i * i != val) v.push_back(val / i);
    }
    
    if (v.size() < K - 2) {
        cout << -1;
        return;
    }
    
    for (int i = 0; i < K - 2; i++) ans.push_back(A * v[i]);
    
    for (ll i: ans) cout << i << " ";
    
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