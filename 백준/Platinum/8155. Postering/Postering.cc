#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[250005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int now = arr[i].second;
        if (st.size() == 0) st.push(now);
        else {
            if (now > st.top()) st.push(now);
            else if (now == st.top()) continue;
            else {
                while (st.size()) {
                    if (st.top() > now) {
                        ans++;
                        st.pop();
                    } else if (st.top() == now) st.pop();
                    else break;
                }
                st.push(now);
            }
        }
    }
    ans += st.size();
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