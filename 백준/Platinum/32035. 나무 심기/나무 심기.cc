#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B;
int ans[405][405];

void solve() {
    cin >> A >> B;
    
    if (B % 2) {
        cout << "NO";
        return;
    }
    if (B == 0) {
        if (A % 2) {
            if ((A - 1) % 3 == 0) {
                cout << "YES\n";
                int x = 0, y = 0;
                ans[0][0] = 1;
                A--;
                while (A) {
                    ans[y][x + 1] = 1;
                    ans[y + 1][x] = 1;
                    ans[x + 1][y + 1] = 1;
                    A -= 3;
                    x++;
                    y++;
                }
                x++;
                y++;
                cout << y << " " << x << '\n';
                for (int i = 0; i < y; i++) {
                    for (int j = 0; j < x; j++) {
                        if (ans[i][j]) cout << "O";
                        else cout << ".";
                    }
                    cout << '\n';
                }
            } else {
                A -= 3;
                if (A < 8) {
                    cout << "NO";
                    return;
                }
                
                cout << "YES\n";
                int len = (A - 6) / 2;
                for (int i = 0; i < 3; i++) ans[i][0] = 1;
                for (int i = 0; i < len; i++) {
                    ans[0][1 + i] = 1;
                    ans[2][1 + i] = 1;
                }
                for (int i = 0; i < 3; i++) ans[i][1 + len] = 1;
                ans[3][len + 1] = 1;
                ans[3][len + 2] = 1;
                ans[2][len + 2] = 1;
                
                cout << 4 << " " << len + 3 << '\n';
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < len + 3; j++) {
                        if (ans[i][j]) cout << "O";
                        else cout << ".";
                    }
                    cout << '\n';
                }
                
            }
            return;
        } else if (A == 2 || A == 6) {
            cout << "NO";
            return;
        } else if ((A - 1) % 3 == 0) {
            cout << "YES\n";
            int x = 0, y = 0;
            ans[0][0] = 1;
            A--;
            while (A) {
                ans[y][x + 1] = 1;
                ans[y + 1][x] = 1;
                ans[x + 1][y + 1] = 1;
                A -= 3;
                x++;
                y++;
            }
            x++;
            y++;
            cout << y << " " << x << '\n';
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (ans[i][j]) cout << "O";
                    else cout << ".";
                }
                cout << '\n';
            }
        } else if (A == 4) {
            cout << "YES\n";
            cout << 2 << " " << 2 << '\n';
            cout << "OO\nOO";
        } else {
            cout << "YES\n";
            int len = (A - 6) / 2;
            for (int i = 0; i < 3; i++) ans[i][0] = 1;
            for (int i = 0; i < len; i++) {
                ans[0][1 + i] = 1;
                ans[2][1 + i] = 1;
            }
            for (int i = 0; i < 3; i++) ans[i][1 + len] = 1;
            cout << 3 << " " << len + 2 << '\n';
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < len + 2; j++) {
                    if (ans[i][j]) cout << "O";
                    else cout << ".";
                }
                cout << '\n';
            }
        }
    } else {
        cout << "YES\n";
        if (B == 2) {
            cout << 1 << " " << A + 2 << '\n';
            for (int i = 0; i < A + 2; i++) cout << "O";
        } else {
            int now = 0;
            cout << 3 << " " << 2 + (B - 2) / 2 + A << '\n';
            ans[1][0] = 1;
            for (int i = 0; i < (B - 2) / 2; i++) {
                ans[1][i + 1] = 1;
                if (now) ans[2][i + 1] = 1;
                else ans[0][i + 1] = 1;
                now ^= 1;
            }
            for (int i = 0; i < A; i++) {
                ans[1][1 + i + (B - 2) / 2] = 1;
            }
            ans[1][(B - 2) / 2 + A + 1] = 1;
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2 + (B - 2) / 2 + A; j++) {
                    if (ans[i][j]) cout << "O";
                    else cout << ".";
                }
                cout << '\n';
            }
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