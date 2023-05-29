#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, R;

void solve() {
    cin >> N >> R;
    N -= R;

    ll ans = 0;
    for(ll i = 1; i * i <= N; i++){
        if(N % i) continue;
        ll a = i, b = N / i;

        if(a == b){
            if(a > R) ans += a;
        }
        else{
            if(a > R) ans += a;
            if(b > R) ans += b;
        }
    }

    cout << ans;
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