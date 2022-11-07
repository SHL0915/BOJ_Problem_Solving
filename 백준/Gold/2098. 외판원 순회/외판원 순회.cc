#include <iostream>
using namespace std;

const long long INF = 1000000000000LL;

long long N;
long long cost[16][16];
long long table[(1 << 16)][16];
long long ans = INF;

long long DP(int city, int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> cost[i][j];		
	}
	cout << DP(0, 1);	
	return 0;
}

long long DP(int city, int state) {
	if (table[state][city] != 0) return table[state][city];
	else if (state == ((1 << N) - 1)) {
		if (cost[city][0] == 0) return INF;
		else return cost[city][0];
	}
	else {		
		table[state][city] = INF;
		for (int i = 0; i < N; i++) {
			if (cost[city][i] == 0) continue;
			if (state & (1 << i)) continue;
			table[state][city] = min(table[state][city], cost[city][i] + DP(i, state + (1 << i)));
		}
		return table[state][city];
	}
}