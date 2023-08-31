#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
set<pair<pii, pii>> S;
string arr[1005];

bool is_cow(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M) return false;
    return arr[i][j] == 'C';
}

int convert(int i, int j) {
    return i * M + j;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 'G') {
                int cnt = 0;
                vector<pii> v;
                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (is_cow(ny, nx)) {
                        cnt++;
                        v.push_back({nx, ny});
                    }
                }

                if (cnt > 2) ans++;
                else if (cnt == 2) {
                    pii a = v[0], b = v[1];
                    if (S.count({a, b}) == 0) {
                        ans++;
                        S.insert({a, b});
                        S.insert({b, a});
                    }
                }
            }
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