#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int cnt[105];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a) cnt[a]++;
    }
    
    int m = 0;
    for (int i = 1; i <= N; i++) m = max(m, cnt[i]);
    
    vector<int> v;
    for (int i = 1; i <= N; i++) if (cnt[i] == m) v.push_back(i);
    
    if (v.size() >= 2) cout << "skipped";
    else cout << v.front();
    
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