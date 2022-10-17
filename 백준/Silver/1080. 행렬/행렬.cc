#include <iostream>
using namespace std;

int N, M, ans;
int A[50][50];
int B[50][50];

void transform(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) A[i][j] = s[j] - '0';
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) B[i][j] = s[j] - '0';
	}
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 3; j++) {
			if (A[i][j] != B[i][j]) {
				transform(j, i);
				ans++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}

void transform(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A[y + i][x + j]++;
			A[y + i][x + j] %= 2;
		}
	}
}