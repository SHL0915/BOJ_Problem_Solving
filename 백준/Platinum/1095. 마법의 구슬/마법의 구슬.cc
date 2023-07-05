#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll S, F, M;
int sieve[100005];
vector<int> pNum;
int cnt[100005];

void solve() {
    cin >> S >> F >> M;

    for (ll i = 2; i <= M; i++) {
        if (sieve[i] == 0) {
            pNum.push_back(i);
            for (ll j = i * i; j <= M; j += i) sieve[j] = 1;
        }
    }

    for (int i = 0; i < pNum.size(); i++) {
        ll now = pNum[i];
        while (now <= (S + F)) {
            cnt[i] += (S + F) / now;
            now *= pNum[i];
        }
    }

    for (int i = 0; i < pNum.size(); i++) {
        ll now = pNum[i];
        while (now <= S) {
            cnt[i] -= S / now;
            now *= pNum[i];
        }
    }

    for (int i = 0; i < pNum.size(); i++) {
        ll now = pNum[i];
        while (now <= F) {
            cnt[i] -= F / now;
            now *= pNum[i];
        }
    }

    for (int i = M; i >= 2; i--) {
        int now = i;
        int flag = 0;
        for(int j = 0; j < pNum.size(); j++) {
            int p = pNum[j];
            int a = 0;
            while(1) {
                if(now % p) break;
                a ++;
                now /= p;
            }
            if(a > cnt[j]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            cout << i;
            return;
        }
    }

    cout << 1;
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