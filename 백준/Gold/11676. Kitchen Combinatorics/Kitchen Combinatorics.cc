#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int R, S, M, D, N;
int ingredient[2005];
vector<int> dish[1005];
int adj[1005][1005];

void solve() {
    cin >> R >> S >> M >> D >> N;
    for (int i = 1; i <= R; i++) cin >> ingredient[i];

    for (int i = 1; i <= S + M + D; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            dish[i].push_back(a);
        }
    }

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    __int128 ans = 0;
    for (int i = 1; i <= S; i++) {
        for (int j = S + 1; j <= S + M; j++) {
            for (int k = S + M + 1; k <= S + M + D; k++) {
                if (adj[i][j] == 1 || adj[i][k] == 1 || adj[j][k] == 1) continue;

                set<int> s;
                for (int a: dish[i]) s.insert(a);
                for (int a: dish[j]) s.insert(a);
                for (int a: dish[k]) s.insert(a);

                __int128 temp = 1;
                for (int a: s) {
                    temp *= ingredient[a];
                    if (temp > 1000000000000000000LL) {
                        cout << "too many";
                        return;
                    }
                }

                ans += temp;
                if (ans > 1000000000000000000LL) {
                    cout << "too many";
                    return;
                }
            }
        }
    }

    cout << (ll)ans;

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