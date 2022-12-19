#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, M, ans = -INF, m, cnt;
ll arr[1005][1005];

void cal();
void BT(ll type, ll base, ll ch);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	cal();
	m = INF;
	for (int i = 1; i < N - 1; i++) {
		cnt = 0;
		for (int j = 0; j < M; j++) cnt += arr[i][j];
		for (int j = 1; j < M - 1; j++) cnt += arr[i][j];
		m = min(m, cnt);
	}
	for (int i = 1; i < N - 1; i++) {
		cnt = 0;
		for (int j = 0; j < M; j++) cnt += arr[i][j];
		for (int j = 1; j < M - 1; j++) cnt += arr[i][j];
		if (cnt == m) {
			BT(0, 0, i);
			BT(0, N - 1, i);
			break;
		}
	}
	m = INF;
	for (int i = 1; i < M - 1; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) cnt += arr[j][i];
		for (int j = 1; j < N - 1; j++) cnt += arr[j][i];
		m = min(m, cnt);
	}
	for (int i = 1; i < M - 1; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) cnt += arr[j][i];
		for (int j = 1; j < N - 1; j++) cnt += arr[j][i];
		if (cnt == m) {
			BT(1, 0, i);
			BT(1, M - 1, i);
			break;
		}
	}
	cout << ans;
	return 0;
}

void cal() {
	long long cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			cnt += (arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1]);
		}
	}	
	ans = max(ans, cnt);
	return;
}

void BT(ll type, ll base, ll ch) {
	ll org[1005];
	ll change[1005];
	if (type == 0) {
		for (int i = 0; i < M; i++) org[i] = arr[base][i];
		for (int i = 0; i < M; i++) change[i] = arr[ch][i];
		for (int i = 0; i < M; i++) {
			arr[base][i] = change[i];
			arr[ch][i] = org[i];
		}
		cal();
		for (int i = 0; i < M; i++) {
			arr[base][i] = org[i];
			arr[ch][i] = change[i];
		}
	}
	else {
		for (int i = 0; i < N; i++) org[i] = arr[i][base];
		for (int i = 0; i < N; i++) change[i] = arr[i][ch];
		for (int i = 0; i < N; i++) {
			arr[i][base] = change[i];
			arr[i][ch] = org[i];
		}
		cal();
		for (int i = 0; i < N; i++) {
			arr[i][base] = org[i];
			arr[i][ch] = change[i];
		}
	}
}