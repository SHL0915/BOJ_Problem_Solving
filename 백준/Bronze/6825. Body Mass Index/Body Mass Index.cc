#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

double A, B;

void solve() {
	cin >> A >> B;
	double BMI = A / (B * B);

	if (BMI > 25) cout << "Overweight";
	else if (BMI >= 18.5) cout << "Normal weight";
	else cout << "Underweight";

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