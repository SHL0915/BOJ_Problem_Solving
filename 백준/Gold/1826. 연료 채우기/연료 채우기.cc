#include <bits/stdc++.h>
using namespace std;

int N, L, P, ans;
pair <int, int> arr[10000];
priority_queue <int> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	cin >> L >> P;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		if (P >= L) break;
		if (arr[i].first <= P) pq.push(arr[i].second);
		else {
			while (pq.size()) {
				if (arr[i].first <= P) break;
				P += pq.top();
				ans++;
				pq.pop();
			}
			if (pq.size() == 0 && arr[i].first > P) {
				cout << -1;
				return 0;
			}
			pq.push(arr[i].second);
		}
	}
	while (pq.size()) {
		if (L <= P) break;
		P += pq.top();
		ans++;
		pq.pop();
	}
	if (pq.size() == 0 && L > P) {
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}