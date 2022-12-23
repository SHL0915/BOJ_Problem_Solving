#include <bits/stdc++.h>
using namespace std;

int N, A, B, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A >> B;
	A--; B--;
	int bit = 1;
	while (1) {
		if (A / bit == B / bit) break;
		bit <<= 1;
		ans++;
	}
	cout << ans;
	return 0;
}