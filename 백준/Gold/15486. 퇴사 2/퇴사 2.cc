#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
pair<int, int> arr[1500001];
long long table[1500001];

long long DP(int today);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int T, P;
		cin >> T >> P;
		arr[i] = { T,P };
	}	
	memset(table, -1, sizeof(table));
	cout << DP(1);
	return 0;
}

long long DP(int today) {
	if (today == N + 1) return 0;
	if (today > N + 1) return -1 * INF;
	if (table[today] != -1) return table[today];
	table[today] = 0;
	table[today] = max(table[today], DP(today + 1));
	table[today] = max(table[today], DP(today + arr[today].first) + arr[today].second);
	return table[today];
}