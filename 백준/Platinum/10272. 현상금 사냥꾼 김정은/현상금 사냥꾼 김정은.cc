#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, N;
pair<ll, ll> arr[512];
double table[512][512];

double DP(int A, int B);
double dist(int pos1, int pos2) {
	ll dx = arr[pos1].first - arr[pos2].first, dy = arr[pos1].second - arr[pos2].second;
	return sqrt(dx * dx + dy * dy);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(6);
	cin >> t;
	while (t--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) table[i][j] = -1;
		}
		cout << DP(0, 0) << '\n';
	}
	return 0;
}

double DP(int A, int B) {	
	double& ret = table[A][B];
	if (ret != -1) return ret;
	if (A == N - 1) ret = dist(B, N - 1);
	else if (B == N - 1) ret = dist(A, N - 1);
	else {
		int next = max(A, B) + 1;
		ret = min(DP(A, next) + dist(B, next), DP(next, B) + dist(A, next));
	}
	return ret;
}