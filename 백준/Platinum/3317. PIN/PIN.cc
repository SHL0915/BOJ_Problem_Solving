#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int A[4][36], B[6][36][36], C[4][36][36][36], D[36][36][36][36];
ll ans[50005][5];

void solve() {
    cin >> N >> M;
    M = 4 - M;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int now[4];
        for (int j = 0; j < 4; j++) {
            if (s[j] >= '0' && s[j] <= '9') now[j] = s[j] - '0' + 26;
            else now[j] = s[j] - 'a';
        }
        
        ans[i][4] = D[now[0]][now[1]][now[2]][now[3]];
        ans[i][3] = C[0][now[0]][now[1]][now[2]] + C[1][now[0]][now[1]][now[3]] + C[2][now[0]][now[2]][now[3]] +
                    C[3][now[1]][now[2]][now[3]] - 4 * ans[i][4];
        ans[i][2] = B[0][now[0]][now[1]] + B[1][now[0]][now[2]] + B[2][now[0]][now[3]] + B[3][now[1]][now[2]] +
                    B[4][now[1]][now[3]] + B[5][now[2]][now[3]] - 3 * ans[i][3] - 6 * ans[i][4];
        ans[i][1] = A[0][now[0]] + A[1][now[1]] + A[2][now[2]] + A[3][now[3]] - 2 * ans[i][2] - 3 * ans[i][3] -
                    4 * ans[i][4];
        ans[i][0] = i - ans[i][1] - ans[i][2] - ans[i][3] - ans[i][4];
        
        for (int j = 0; j < 4; j++) A[j][now[j]]++;
        
        B[0][now[0]][now[1]]++;
        B[1][now[0]][now[2]]++;
        B[2][now[0]][now[3]]++;
        B[3][now[1]][now[2]]++;
        B[4][now[1]][now[3]]++;
        B[5][now[2]][now[3]]++;
        
        C[0][now[0]][now[1]][now[2]]++;
        C[1][now[0]][now[1]][now[3]]++;
        C[2][now[0]][now[2]][now[3]]++;
        C[3][now[1]][now[2]][now[3]]++;
        
        D[now[0]][now[1]][now[2]][now[3]]++;
    }
    
    ll aans = 0;
    
    for (int i = 0; i < N; i++) aans += ans[i][M];
    
    cout << aans;
    
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