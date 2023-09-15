#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, B;
int pi[1000005];
vector<int> ans;

bool check(int i, int j, string &S, string &T) {
    return S[i] == T[j];
}

void make_pi() {
    for (int i = 1, j = 0; i < B.length(); i++) {
        while (j && !check(i, j, B, B)) j = pi[j - 1];
        if (check(i, j, B, B)) pi[i] = ++j;
    }
    return;
}

void kmp() {
    for (int i = 0, j = 0; i < A.length(); i++) {
        while (j && !check(i, j, A, B)) j = pi[j - 1];
        if (check(i, j, A, B)) {
            if (j == B.length() - 1) ans.push_back(i - j + 1), j = pi[j];
            else j++;
        }
    }
    return;
}

void solve() {
    getline(cin, A);
    getline(cin, B);
    make_pi();
    kmp();
    cout << ans.size() << '\n';
    for (int a: ans) cout << a << " ";
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