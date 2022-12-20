#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;
const int INF = 0x3f3f3f3f;

int N, M, K, ans = INF;
int org[51][51];
int arr[51][51];
piii oper[10];
int bt[10];
int mark[10];

void BackTracking(int k);
void rotate(int r, int c, int s);
int cal();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> org[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) arr[i][j] = org[i][j];
	}
	for (int i = 0; i < K; i++) cin >> oper[i].first.first >> oper[i].first.second >> oper[i].second;
	BackTracking(0);
	cout << ans;
	return 0;
}

void BackTracking(int k) {
	if (k == K) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) arr[i][j] = org[i][j];
		}
		for (int i = 0; i < K; i++) {
			int r = oper[bt[i]].first.first;
			int c = oper[bt[i]].first.second;
			int s = oper[bt[i]].second;
			rotate(r, c, s);
		}
		ans = min(ans, cal());
		return;
	}
	else {
		for (int i = 0; i < K; i++) {
			if (mark[i] == 0) {
				bt[k] = i;
				mark[i] = 1;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}

void rotate(int r, int c, int s) {
	if (s == 0) return;
	int temp[51][51];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) temp[i][j] = arr[i][j];
	}

	arr[r - s][c - s] = temp[r - s + 1][c - s];
	for (int j = c - s + 1; j <= c + s; j++) arr[r - s][j] = temp[r - s][j - 1];
	for (int i = r - s + 1; i <= r + s - 1; i++) {
		arr[i][c - s] = temp[i + 1][c - s];
		arr[i][c + s] = temp[i - 1][c + s];
	}
	arr[r + s][c + s] = temp[r + s - 1][c + s];
	for (int j = c - s; j <= c + s - 1; j++) arr[r + s][j] = temp[r + s][j + 1];
	rotate(r, c, s - 1);
}

int cal() {
	int m = INF;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= M; j++) cnt += arr[i][j];
		m = min(m, cnt);
	}
	return m;
}