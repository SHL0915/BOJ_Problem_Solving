#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
int sieve[100000005];
vector<int> p;

void solve() {
    if (N < 8) {
        cout << "Impossible.\n";
        return;
    }
    
    vector<int> ans;
    if (N % 2) {
        ans.push_back(2);
        ans.push_back(3);
        N -= 5;
    } else {
        ans.push_back(2);
        ans.push_back(2);
        N -= 4;
    }
    
    for (int a: p) {
        if (!sieve[N - a]) {
            ans.push_back(a);
            ans.push_back(N - a);
            break;
        }
    }
    
    for (int a: ans) cout << a << " ";
    cout << '\n';
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    for (ll i = 2; i <= 100000000; i++) {
        if (!sieve[i]) {
            p.push_back(i);
            for (ll j = i * i; j <= 100000000; j += i) sieve[j] = 1;
        }
    }
    
    //cin >> t;
    while (cin >> N) solve();
    return 0;
}