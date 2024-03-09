#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    cin >> N;
    stack<int> st;

    int now = 1;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == now) now++;
        else {
            while (st.size()) {
                if (st.top() == now) {
                    now++;
                    st.pop();
                } else break;
            }
            st.push(a);
        }
    }

    while (st.size()) {
        if (st.top() == now) {
            now++;
            st.pop();
        } else break;
    }

    if (now == N + 1) cout << "Nice";
    else cout << "Sad";

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