#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, U, L;

void solve() {
    cin >> N >> U >> L;
    bool a = (N >= 1000);
    bool b = (U >= 8000 || L >= 260);
    if (a && b) cout << "Very Good";
    else if (a) cout << "Good";
    else cout << "Bad";
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