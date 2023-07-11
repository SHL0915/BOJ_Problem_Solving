#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int org[100005];
int arr[300005];

void solve() {
	cin >> N;
	ll val = 0;
	for (int i = 0; i < N; i++) {
		cin >> org[i];
		val += org[i];
	}

	val /= N;

	for (int i = 0; i < N; i++) org[i] = org[i] - val;

	for (int i = 0; i < N; i++) arr[i] = org[i];
	priority_queue <pii, vector<pii>, greater<>> pq;

	ll cal = 0, ans = 0;

	for (int i = 0; i < 2 * N; i++) {
		if (arr[i] > 0) pq.push({ i, arr[i] });
		else if (arr[i] < 0) {
			while (pq.size()) {
				pii t = pq.top();
				pq.pop();
				ll now = min(-arr[i], t.second);
				cal += now * (i - t.first);
				arr[i] += now;
				t.second -= now;
				if (t.second != 0) pq.push(t);
				if (arr[i] == 0) break;
			}
			if (arr[i] < 0) arr[i + N] = arr[i];
		}
	}

	while (pq.size()) pq.pop();
	
	ans = cal;
	for (int i = 0; i < N; i++) arr[i] = org[N - 1 - i];
			
	cal = 0;

	for (int i = 0; i < 2 * N; i++) {
		if (arr[i] > 0) pq.push({ i, arr[i] });
		else if (arr[i] < 0) {
			while (pq.size()) {
				pii t = pq.top();
				pq.pop();
				ll now = min(-arr[i], t.second);
				cal += now * (i - t.first);
				arr[i] += now;
				t.second -= now;
				if (t.second != 0) pq.push(t);
				if (arr[i] == 0) break;
			}
			if (arr[i] < 0) arr[i + N] = arr[i];
		}
	}
	
	ans = min(ans, cal);

	cout << ans;
	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
