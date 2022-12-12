#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
int avoid[201][201];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		avoid[A][B] = 1;
		avoid[B][A] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (avoid[i][j] + avoid[i][k] + avoid[j][k] == 0) cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}