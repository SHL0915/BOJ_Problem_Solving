#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    cin >> N;
    stack <int> st;

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        switch (a) {
            case 1:
                int b;
                cin >> b;
                st.push(b);
                break;
            case 2:
                if(st.size()) {
                    cout << st.top() << '\n';
                    st.pop();
                }
                else cout << -1 << '\n';
                break;
            case 3:
                cout << st.size() << '\n';
                break;
            case 4:
                if(st.size()) cout << 0 << '\n';
                else cout << 1 << '\n';
                break;
            case 5:
                if(st.size()) cout << st.top() << '\n';
                else cout << -1 << '\n';
                break;
        }
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