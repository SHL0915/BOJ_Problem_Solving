#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
string in;
string ok = "absent";

void solve() {
    cin >> N;
    int ridx = 1;
    for (int lidx = 0; lidx < N;) {
        for (; ridx <= N; ridx++) {
            cout << "? " << lidx << " " << ridx << endl;
            cin >> in;
            if (in == ok) {
                ans++;
                break;
            }
        }
        lidx = ridx;
        ridx++;
    }
    
    cout << "! " << ans << endl;
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}