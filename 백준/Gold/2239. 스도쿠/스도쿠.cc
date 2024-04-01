#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[9][9];
vector<pii> pos;

bool chk(int x, int y) {
    
    for (int i = 0; i < 9; i++) {
        if (i == y) continue;
        if (arr[i][x] == arr[y][x]) return false;
    }
    
    for (int i = 0; i < 9; i++) {
        if (i == x) continue;
        if (arr[y][i] == arr[y][x]) return false;
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int xx = (x / 3) * 3 + j, yy = (y / 3) * 3 + i;
            if (xx == x && yy == y) continue;
            if (arr[yy][xx] == arr[y][x]) return false;
        }
    }
    
    return true;
}

void BackTracking(int idx) {
    
    if (idx == pos.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << arr[i][j];
            cout << '\n';
        }
        exit(0);
    }
    
    for (int i = 1; i < 10; i++) {
        int x = pos[idx].second, y = pos[idx].first;
        arr[y][x] = i;
        if (!chk(x, y)) arr[y][x] = 0;
        else {
            BackTracking(idx + 1);
            arr[y][x] = 0;
        }
    }
    
    return;
}

void solve() {
    
    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++) {
            arr[i][j] = s[j] - '0';
            if (!arr[i][j]) pos.push_back({i, j});
        }
    }
    
    BackTracking(0);
    
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