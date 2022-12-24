#include <bits/stdc++.h>
using namespace std;

int N, sum, M;
pair<int, int> arr[100001];

int absol(int A) {
	if (A >= 0) return A;
	else return -A;
}

int dist(pair<int, int> A, pair<int, int> B) {
	return absol(A.first - B.first) + absol(A.second - B.second);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 2; i <= N; i++) {
		if (i < N) {
			M = max(M, dist(arr[i], arr[i - 1]) + dist(arr[i + 1], arr[i]) - dist(arr[i + 1], arr[i - 1]));
		}
		sum += dist(arr[i], arr[i - 1]);
	}
	cout << sum - M;
	return 0;
}