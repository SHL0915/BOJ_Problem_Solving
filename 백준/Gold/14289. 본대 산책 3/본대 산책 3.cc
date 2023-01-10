#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int N, M, D;
long long graph[51][51];
long long result[51][51];

void power(long long N);
void mul(long long A[51][51], long long B[51][51]);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;		
		result[a][b] = 1;
		result[b][a] = 1;
	}	
	cin >> D;
	power(D - 1);
	cout << result[1][1];
	return 0;
}

void power(long long N) {
	long long bit = 1;
	while (bit <= N) {
		if (bit & N) mul(result, graph);
		mul(graph, graph);
		bit <<= 1;
	}
	return;
}

void mul(long long A[51][51], long long B[51][51]) {
	long long temp[51][51];
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			temp[i][j] = 0;
			for (int a = 0; a < 51; a++) {
				temp[i][j] += A[i][a] * B[a][j];
				temp[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) A[i][j] = temp[i][j];
	}
	return;
}