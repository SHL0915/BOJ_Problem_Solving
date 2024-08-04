#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii s;
int arr[55][55];
int grid[55][55];

void solve() {
    cin >> N;
    cin >> s.first >> s.second;
    s.first--, s.second--;
    for(int i = 0; i < N; i++) {
        string a;
        cin >> a;
        for(int j = 0; j < N; j++) if(a[j] == '#') arr[i][j] = 1;
    }

    vector <pair<pii, int>> ans;

    grid[s.first][s.second] = 1;

    pii now = s;
    while(now.second < N - 1) {
        ans.push_back({{2, now.first}, 0});
        now.second++;
        grid[now.first][now.second] = 1;
    }

    now = s;

    while(now.second) {
        ans.push_back({{0, now.first}, 0});
        now.second--;
        grid[now.first][now.second] = 1;
    }
    
    s = now;
    now = s;
    while(now.first) {
        ans.push_back({{3, now.second}, 0});
        now.first--;
        grid[now.first][now.second] = 1;
    }

    now = s;
    while(now.first < N - 1) {
        ans.push_back({{1, now.second}, 0});
        now.first++;
        grid[now.first][now.second] = 1;
    }

    for(int i = 1; i < N; i++) {
        if(arr[s.first][i] == 0) {
            ans.push_back({{3, i}, 1});
            grid[s.first][i] = 0;
        }
    }

    for(int i = s.first - 1; i >= 0; i--) {
        int cnt = 0;
        for(int j = 1; j < N; j++) cnt += arr[i][j];
        if(!cnt) continue;

        for(int j = 1; j < N; j++) {
            ans.push_back({{2, i}, 0});
            grid[i][j] = 1;
        }

        for(int j = 1; j < N; j++) {
            if(arr[i][j] == 0) {
                ans.push_back({{3, j}, 1});
                grid[i][j] = 0;
            }
        }
    }

    for(int i = s.first + 1; i < N; i++) {
        int cnt = 0;
        for(int j = 1; j < N; j++) cnt += arr[i][j];
        if(!cnt) continue;

        for(int j = 1; j < N; j++) {
            ans.push_back({{2, i}, 0});
            grid[i][j] = 1;
        }

        for(int j = 1; j < N; j++) {
            if(arr[i][j] == 0) {
                ans.push_back({{1, j}, 1});
                grid[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(!arr[i][0]) {
            ans.push_back({{0, i}, 1});
            grid[i][0] = 0;
        }
    }

    assert(ans.size() <= 2 * N * N);

    cout << ans.size() << '\n';

    for(auto i : ans) {
        int d = i.first.first, a = i.first.second, b = i.second;
        if(d == 0) cout << "L ";
        else if(d == 1) cout << "D ";
        else if(d == 2) cout << "R ";
        else cout << "U ";

        cout << a + 1 << " ";

        if(b == 0) cout << "push\n";
        else cout << "pull\n";
    }
    
}


int main(void) {
    ios::sync_with_stdio(false);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) solve();

    return 0;
}