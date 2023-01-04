#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, ans, cnt = INF;
pair<int, int> arr[101];
int t[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		for (int j = arr[i].first; j < arr[i].second; j++) t[j] ++;
	}
	for (int i = 0; i < N; i++) {
		int c = 0;
		for (int j = arr[i].first; j < arr[i].second; j++) if (t[j] == 1) c++;
		cnt = min(cnt, c);
	}
	for (int i = 0; i < 1001; i++) if (t[i]) ans++;
	cout << ans - cnt;
	return 0;
}