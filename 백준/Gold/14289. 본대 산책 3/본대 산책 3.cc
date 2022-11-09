#include <iostream>
using namespace std;

const long long mod = 1000000007;

int N, M, D;
long long graph[50][50];
long long result[50][50];

void power(long long n);
void mul(long long A[50][50], long long B[50][50]);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a][b] = 1;
		graph[b][a] = 1;
		result[a][b] = 1;
		result[b][a] = 1;
	}
	cin >> D;		
	power(D - 1);
	cout << result[0][0];
	return 0;
}

void power(long long n) {
	long long bit = 1;
	while (bit <= n) {
		if (bit & n) mul(result, graph);
		mul(graph, graph);
		bit <<= 1;
	}
	return;
}

void mul(long long A[50][50], long long B[50][50]) {
	long long temp[50][50];
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) temp[i][j] = 0;
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 50; k++) {
				temp[i][j] += (A[i][k] * B[k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) A[i][j] = temp[i][j];
	}
}