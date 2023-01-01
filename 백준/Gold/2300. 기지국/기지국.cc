#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
pair<int, int> arr[10001];
int table[10001];

int DP(int start);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
		if (arr[i].second < 0) arr[i].second *= -1;		
	}
	sort(arr + 1, arr + N + 1);
	memset(table, -1, sizeof(table));
	cout << DP(1);
	return 0;
}

int DP(int start) {
	if (start > N) return 0;
	int& ret = table[start];
	if (ret != -1) return ret;
	ret = INF;
	int max_val = 0;
	for (int i = start; i <= N; i++) {
		max_val = max(max_val, arr[i].second);
		ret = min(ret, max(arr[i].first - arr[start].first, max_val * 2) + DP(i + 1));		
	}
	return ret;
}