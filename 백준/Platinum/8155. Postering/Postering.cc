#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[250005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = b;
    }

    stack<int> st;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int now = arr[i];
        if (st.size() == 0) st.push(now);
        else {
            if (now > st.top()) st.push(now);
            else if (now == st.top()) continue;
            else {
                while (st.size()) {
                    int t = st.top();
                    if (t > now) {
                        ans++;
                        st.pop();
                    } else break;
                }
                if (st.size() == 0 || st.top() < now) st.push(now);
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