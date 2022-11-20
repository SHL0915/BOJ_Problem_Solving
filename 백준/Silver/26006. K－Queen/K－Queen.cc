#include <iostream>
using namespace std;

int N, K, R, C;
pair <int, int> queen[100000];

int check(int x, int y);
int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> R >> C;
	for (int i = 0; i < K; i++) {
		int A, B;
		cin >> A >> B;
		queen[i] = { B,A };
	}
	int ans = 0;
	int now = check(C, R);
	ans = (check(C, R) + check(C - 1, R) + check(C + 1, R) + check(C, R - 1) + check(C, R + 1) + check(C - 1, R - 1) + check(C - 1, R + 1) + check(C + 1, R - 1) + check(C + 1, R + 1));
	if (ans == 9) cout << "CHECKMATE";
	else if (now == 1) cout << "CHECK";
	else if (now == 0 && ans == 8) cout << "STALEMATE";
	else cout << "NONE";
	return 0;
}

int check(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > N) return 1;
	for (int i = 0; i < K; i++) {
		if (x == queen[i].first) return 1;
		if (y == queen[i].second) return 1;
		if (absol(x - queen[i].first) == absol(y - queen[i].second)) return 1;
	}
	return 0;
}