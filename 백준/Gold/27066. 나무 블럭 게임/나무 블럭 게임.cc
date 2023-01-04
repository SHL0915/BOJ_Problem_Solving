#include <bits/stdc++.h>
using namespace std;

int N, sum;
int arr[100001];
priority_queue <int> pq;
double ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		pq.push(arr[i]);
	}
	if (N == 1) {
		cout << sum;
		return 0;
	}
	ans = (double)sum / N;
	for (int i = 0; i < N; i++) ans = max(ans, min((double)(sum - arr[i]) / (N - 1), (double)arr[i]));
	pq.pop();
	ans = max(ans, (double)pq.top());
	cout << ans;
	return 0;
}