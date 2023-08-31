#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, N;
map<string, int> id;
int ans[105][105];
set<int> S[105];

void solve() {
    cin >> K >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        id[s] = i;
    }

    memset(ans, -1, sizeof(ans));

    for (int i = 0; i < K; i++) {
        vector<string> v(N);
        for (int j = 0; j < N; j++) cin >> v[j];

        for (int j = 0; j < N; j++) {
            for (int k = j; k < N; k++) {
                if (v[j] > v[k]) {
                    for (int l = k; l < N; l++) {
                        for(int m = j; m >= 0; m --) {
                            int a = id[v[m]], b = id[v[l]];
                            ans[a][b] = 0;
                            ans[b][a] = 1;
                        }
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) cout << "B";
            else if (ans[i][j] == -1) cout << "?";
            else cout << ans[i][j];
        }
        cout << '\n';
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