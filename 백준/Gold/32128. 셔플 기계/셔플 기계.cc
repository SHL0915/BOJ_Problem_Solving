#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int N, M, K;
vector<int> S[1005];
int sparse[1005][1005][32];

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            S[i].push_back(a);
            sparse[i][j + 1][0] = a;
        }
        for (int j = 1; j < 32; j++) {
            for (int k = 1; k <= N; k++) sparse[i][k][j] = sparse[i][sparse[i][k][j - 1]][j - 1];
        }
    }
    
    vector<int> ans(N + 1), pos(N + 1), temp(N + 1);
    for (int i = 1; i <= N; i++) ans[i] = i, pos[i] = i;
    
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        ll bit = 1, cnt = 0;
        
        while (bit <= y) {
            if (y & bit) {
                for (int j = 1; j <= N; j++) {
                    int now = sparse[x][j][cnt];
                    temp[now] = ans[j];
                }
                for (int j = 1; j <= N; j++) ans[j] = temp[j];
            }
            bit <<= 1;
            cnt++;
        }
    }
    
    for(int i = 1; i <= N; i++) cout << ans[i] << " ";
    
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}