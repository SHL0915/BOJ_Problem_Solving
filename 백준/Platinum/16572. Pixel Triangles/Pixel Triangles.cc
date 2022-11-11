#include <iostream>
#include <algorithm>
using namespace std;

int N, cnt;
int mark[2001][2001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		mark[B][A] = max(mark[B][A], C);
	}
	for (int i = 1; i <= 2000; i++) {
		for (int j = 1; j <= 2000; j++) {
			int val = 0;
			val = max(mark[i - 1][j] - 1, mark[i][j - 1] - 1);
			val = max(val, mark[i][j]);
			mark[i][j] = val;
			if (mark[i][j] != 0) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
