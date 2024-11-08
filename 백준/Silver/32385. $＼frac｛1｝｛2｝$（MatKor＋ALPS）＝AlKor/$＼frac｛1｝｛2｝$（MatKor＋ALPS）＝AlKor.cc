#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    cin >> N;
    vector<int> ans;
    int n = N;
    if (N % 2) {
        ans.push_back(0);
        N--;
    }
    
    int med = N / 2 + 1;
    
    for (int i = 1; i <= N / 2; i++) ans.push_back(i * n);
    for (int i = 1; i <= N / 2; i++) ans.push_back(med * n + i * n);
    
    ll sum = 0;
    for (int i: ans) sum += i;
    ans.push_back(sum / ans.size());
    
    for (int i: ans) cout << i << " ";
    
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