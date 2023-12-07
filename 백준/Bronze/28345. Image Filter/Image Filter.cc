#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int R, C;
int arr[105][105];

void solve() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cin >> arr[i][j];
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            vector<pii> v;
            int A = arr[i][j - 1];
            int B = arr[i - 1][j];
            int CC = arr[i - 1][j - 1];
            v.push_back({0, arr[i][j]});
            v.push_back({1, arr[i][j] - A});
            v.push_back({2, arr[i][j] - B});
            v.push_back({3, arr[i][j] - (A + B) / 2});
            v.push_back({4, arr[i][j] - (A + B - CC)});
            sort(v.begin(), v.end(), [&](pii a, pii b) {
                if (abs(a.second) == abs(b.second)) return a.first < b.first;
                else return abs(a.second) < abs(b.second);
            });
            cout << v.front().first << " " << v.front().second << " ";
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
    cin >> t;
    while (t--) solve();
    return 0;
}