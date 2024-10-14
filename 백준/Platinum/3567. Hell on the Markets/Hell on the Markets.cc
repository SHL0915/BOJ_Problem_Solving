#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int ans[100005];

void solve() {
    cin >> N;

    ll sum = 0;
    set <pii> s;
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        sum += a;
        s.insert({a, i});
    }

    if (sum % 2) {
        cout << "No";
        return;
    }

    ll now = sum / 2;
    while(now) {
        pii e = {now, 1e9};
        auto it = s.upper_bound(e);
        it--;
        ans[(*it).second] = 1;
        now -= (*it).first;
        s.erase(it);
    }
    
    cout << "Yes\n";
    for(int i = 1; i <= N; i++) {
        if(ans[i]) cout << 1 << " ";
        else cout << -1 << " ";
    }

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