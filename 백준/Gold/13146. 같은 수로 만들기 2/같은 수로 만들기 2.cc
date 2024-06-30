#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    cin >> N;
    stack<ll> st;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (st.empty()) st.push(a);
        else {
            ll t = st.top();
            if (a == t) continue;
            else if (a > t) {
                ans += a - t;
                while (st.size()) {
                    if (st.top() <= a) st.pop();
                    else break;
                }
                st.push(a);
            } else st.push(a);
        }
    }
    
    while (st.size() > 1) {
        ll t = st.top();
        st.pop();
        ans += st.top() - t;
    }
    
    cout << ans;
    
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