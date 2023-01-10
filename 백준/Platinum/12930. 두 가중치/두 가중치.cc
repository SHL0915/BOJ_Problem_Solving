#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, ans = INF;
int graph1[21][21];
int graph2[21][21];
int table[21][201][201];

void DP(int pos, int w1, int w2);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '.') graph1[i][j] = -1;
			else graph1[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '.') graph2[i][j] = -1;
			else graph2[i][j] = s[j] - '0';
		}
	}
	memset(table, -1, sizeof(table));
	DP(0, 0, 0);
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) if (table[1][i][j] == 1) ans = min(ans, i * j);
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void DP(int pos, int w1, int w2) {
	if (w1 > 200 || w2 > 200) return;	
	if (table[pos][w1][w2] != -1) return;
	table[pos][w1][w2] = 1;
	if (pos == 1) return;
	for (int i = 0; i < N; i++) {
		if (graph1[pos][i] != -1) DP(i, w1 + graph1[pos][i], w2 + graph2[pos][i]);
	}
	return;
}