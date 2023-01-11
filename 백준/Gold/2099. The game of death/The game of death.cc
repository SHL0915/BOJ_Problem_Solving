#include <bits/stdc++.h>
using namespace std;

int N, K, M;
int graph[201][201];
int result[201][201];

void power(int k);
void mul(int A[201][201], int B[201][201]);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		graph[i][a] = 1;
		graph[i][b] = 1;
		result[i][a] = 1;
		result[i][b] = 1;
	}
	power(K - 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (result[a][b]) cout << "death\n";
		else cout << "life\n";
	}
	return 0;
}

void power(int k) {
	int bit = 1;
	while (bit <= k) {
		if (bit & k) mul(result, graph);
		mul(graph, graph);
		bit <<= 1;
	}
	return;
}

void mul(int A[201][201], int B[201][201]) {
	int temp[201][201];
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < 201; k++) temp[i][j] += A[i][k] * B[k][j];			
		}
	}
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			if (temp[i][j]) A[i][j] = 1;
			else A[i][j] = 0;
		}
	}
	return;
}