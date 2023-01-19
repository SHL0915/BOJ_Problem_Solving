#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B;

int GCD(int a, int b);
int LCM(int a, int b);

void solve() {
	cin >> A >> B;
	cout << GCD(A, B) << '\n' << LCM(A, B);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int GCD(int a, int b) {
	if (a > b) {
		if (a % b) return GCD(a % b, b);
		else return b;
	}
	else {
		if (b % a) return GCD(b % a, a);
		else return a;
	}
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}