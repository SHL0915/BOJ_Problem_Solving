#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
string arr[100001][2];
ll ans[100001][2];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1];

	ans[0][0] = 1;
	ans[0][1] = 1;

	for (int i = 1; i <= N; i++) {
		ans[i][1] = ans[i - 1][0];

		switch (arr[i][0].front()) {
		case '+': 
			ans[i][0] = max(ans[i][0], ans[i - 1][0] + (arr[i][0][1] - '0')); 
			ans[i][1] = max(ans[i][1], ans[i - 1][1] + (arr[i][0][1] - '0'));
			break;
		case '-': 
			ans[i][0] = max(ans[i][0], ans[i - 1][0] - (arr[i][0][1] - '0'));
			ans[i][1] = max(ans[i][1], ans[i - 1][1] - (arr[i][0][1] - '0'));
			break;
		case '*': 
			ans[i][0] = max(ans[i][0], ans[i - 1][0] * (arr[i][0][1] - '0'));
			ans[i][1] = max(ans[i][1], ans[i - 1][1] * (arr[i][0][1] - '0'));
			break;
		case '/': 
			ans[i][0] = max(ans[i][0], ans[i - 1][0] / (arr[i][0][1] - '0'));
			ans[i][1] = max(ans[i][1], ans[i - 1][1] / (arr[i][0][1] - '0'));
			break;
		}

		switch (arr[i][1].front()) {
		case '+':
			ans[i][0] = max(ans[i][0], ans[i - 1][0] + (arr[i][1][1] - '0'));
			ans[i][1] = max(ans[i][1], ans[i - 1][1] + (arr[i][1][1] - '0'));
			break;
		case '-':
			ans[i][0] = max(ans[i][0], ans[i - 1][0] - (arr[i][1][1] - '0'));
			ans[i][1] = max(ans[i][1], ans[i - 1][1] - (arr[i][1][1] - '0'));
			break;
		case '*':
			ans[i][0] = max(ans[i][0], ans[i - 1][0] * (arr[i][1][1] - '0'));
			ans[i][1] = max(ans[i][1], ans[i - 1][1] * (arr[i][1][1] - '0'));
			break;
		case '/':
			ans[i][0] = max(ans[i][0], ans[i - 1][0] / (arr[i][1][1] - '0'));
			ans[i][1] = max(ans[i][1], ans[i - 1][1] / (arr[i][1][1] - '0'));
			break;
		}

		if (ans[i][0] <= 0) ans[i][0] = -INF;
		if (ans[i][1] <= 0) ans[i][1] = -INF;
		
		if (ans[i][0] <= 0 && ans[i][1] <= 0) {
			cout << "ddong game";
			return;
		}	
	}

	cout << max(ans[N][0], ans[N][1]);
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