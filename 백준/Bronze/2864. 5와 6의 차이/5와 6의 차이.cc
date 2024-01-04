#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, B;
string ma, mb, Ma, Mb;

void solve() {
    cin >> A >> B;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] == '5' || A[i] == '6') {
            ma += '5';
            Ma += '6';
        } else {
            ma += A[i];
            Ma += A[i];
        }
    }
    
    for (int i = 0; i < B.length(); i++) {
        if (B[i] == '5' || B[i] == '6') {
            mb += '5';
            Mb += '6';
        } else {
            mb += B[i];
            Mb += B[i];
        }
    }
    
    ll a = stoi(ma, 0, 10) + stoi(mb, 0, 10);
    ll b = stoi(Ma, 0, 10) + stoi(Mb, 0, 10);
    
    cout << a << " " << b;
    
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