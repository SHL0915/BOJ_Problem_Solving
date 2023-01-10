#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000003;

ll N, S, E, T;
ll graph[51][51];
ll result[51][51];

void init();
void power(ll N);
void mul(ll A[51][51], ll B[51][51]);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> N >> S >> E >> T;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			int val = s[j] - '0';
			if (val == 0) continue;
			graph[i * 5][j * 5 + val - 1] = 1;
			result[i * 5][j * 5 + val - 1] = 1;
		}
	}	
	power(T - 1);
	cout << result[(S - 1) * 5][(E - 1) * 5];
	return 0;
}

void init() {
	for (int i = 0; i < 51; i++) {
		if (i % 5) {
			graph[i][i - 1] = 1;
			result[i][i - 1] = 1;
		}
	}
	return;
}

void power(ll N) {
	ll bit = 1;
	while (bit <= N) {
		if (bit & N) mul(result, graph);
		mul(graph, graph);
		bit <<= 1;
	}
	return;
}

void mul(ll A[51][51], ll B[51][51]) {
	ll temp[51][51];
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < 51; k++) {
				temp[i][j] += (A[i][k] * B[k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) A[i][j] = temp[i][j];
	}
	return;
}