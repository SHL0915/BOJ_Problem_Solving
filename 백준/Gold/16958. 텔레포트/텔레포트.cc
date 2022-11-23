#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;

int N, T, M;
piii city[1000];
int adj[1000][1000];

int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		city[i] = { {x,y},s };
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			adj[i][j] = absol(city[i].first.first - city[j].first.first) + absol(city[i].first.second - city[j].first.second);
			if (city[i].second == 1 && city[j].second == 1) adj[i][j] = min(adj[i][j], T);
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << adj[A - 1][B - 1] << '\n';
	}
	return 0;
}