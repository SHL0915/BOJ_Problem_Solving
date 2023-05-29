#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
vector <int> rpos, bpos;
string S;

void solve() {
    cin >> N >> Q;
    cin >> S;
    for(int i = 0; i < S.length(); i++){
        if(S[i] == 'R') rpos.push_back(i);
        else if(S[i] == 'B') bpos.push_back(i);
    }

    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;

        int r1 = -1, r2 = -1, b1 = -1, b2 = -1;

        r1 = lower_bound(rpos.begin(), rpos.end(), l) - rpos.begin();
        if(r1 == rpos.size() || rpos[r1] > r) {
            cout << -1 << '\n';
            continue;
        }

        r2 = lower_bound(rpos.begin(), rpos.end(), rpos[r1] + 1) - rpos.begin();
         if(r2 == rpos.size() || rpos[r2] > r) {
            cout << -1 << '\n';
            continue;
        }

        b1 = lower_bound(bpos.begin(), bpos.end(), rpos[r2] + 1) - bpos.begin();
        if(b1 == bpos.size() || bpos[b1] > r) {
            cout << -1 << '\n';
            continue;
        }

        b2 = lower_bound(bpos.begin(), bpos.end(), bpos[b1] + 1) - bpos.begin();
        if(b2 == bpos.size() || bpos[b2] > r) {
            cout << -1 << '\n';
            continue;
        }

        cout << rpos[r1] << " " << rpos[r2] << " " << bpos[b1] << " " << bpos[b2] << '\n';
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