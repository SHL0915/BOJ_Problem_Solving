#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, L;
vector <int> arr[1001];
int pi[10001];
int cmp[10001];
vector <int> ans;

void makePi();
bool kmp(int idx);

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            arr[i].push_back(a);
        }
    }
    cin >> L;
    int first; cin >> first;
    for (int i = 1; i < L; i++) {
        int a; cin >> a;
        cmp[i] = a - first;
    }

    makePi();

    for (int i = 1; i <= N; i++) {
        if (kmp(i) == true) ans.push_back(i);
    }

    if (ans.size() == 0) cout << -1;
    else {
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
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

void makePi() {
    int n = L, pos = 1, k = 0;
    while (pos + k < n) {
        if (cmp[pos + k] - cmp[pos] == cmp[k]) {
            k++;
            pi[pos + k - 1] = k;
        }
        else {
            if (k == 0) pos++;
            else {
                pos += (k - pi[k - 1]);
                k = pi[k - 1];
            }
        }
    }
    return;
}

bool kmp(int idx) {
    vector <int>& org = arr[idx];
    int n = org.size(), m = L, pos = 0, k = 0;
    while (pos + m <= n) {
        if (k < m && org[pos + k] - org[pos] == cmp[k]) {
            k++;
            if (k == m) return true;
        }
        else {
            if (k == 0) pos++;
            else {
                pos += (k - pi[k - 1]);
                k = pi[k - 1];
            }
        }
    }
    return false;
}