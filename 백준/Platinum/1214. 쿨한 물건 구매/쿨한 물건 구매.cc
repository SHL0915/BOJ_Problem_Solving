#include <bits/stdc++.h>
using namespace std;

int D, P, Q, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> D >> P >> Q;
	if (P < Q) swap(P, Q);
	int M = (D % P) ? D / P + 1 : D / P;
	ans = M * P;
	for (int i = M - 1; i >= 0; i--) {		
		int now = D - P * i;
		if (now % Q == 0) {
			ans = D;
			break;
		}
		else {
			int cmp = (i * P) + ((now / Q) + 1) * Q;
			if (ans == cmp) break;
			ans = min(ans, cmp);
		}
	}
	cout << ans;
	return 0;
}