#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string A, B;
int par[100005];
int arr[100005];

int find(int a) {
    if (a == par[a]) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    par[find(a)] = find(b);
}

void solve() {
    cin >> N;
    cin >> A >> B;

    for (int i = 0; i < N; i++) par[i] = i;

    int flag = 0, idx = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] == '1') merge(i, (i - 1 + N) % N);
        else flag = 1, idx = i;
    }

    ll ans = 0;

    if (!flag) {
        ll cnt = 0;
        for (int i = 0; i < N; i++) if (B[i] == '1') cnt++;
        ans = (cnt * (cnt - 1)) + 1;
    } else {
        int s = idx;
        while (1) {
            int e = s;
            int cnt = 0;
            while (1) {
                if (B[e] == '1') cnt++;
                if (find(s) != find((e + 1) % N) || (e + 1) % N == idx) break;
                e = (e + 1) % N;
            }
            ans += (cnt * (cnt - 1)) / 2;
            if ((e + 1) % N == idx) break;
            s = (e + 1) % N;
        }
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