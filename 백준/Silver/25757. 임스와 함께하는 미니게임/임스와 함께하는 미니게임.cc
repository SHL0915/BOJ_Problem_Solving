#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
char M;
set<string> s;

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        s.insert(a);
    }
    if (M == 'Y') cout << s.size() << '\n';
    else if (M == 'F') cout << s.size() / 2 << '\n';
    else cout << s.size() / 3 << '\n';
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