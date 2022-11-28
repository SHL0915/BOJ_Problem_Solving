#include <bits/stdc++.h>
using namespace std;

int Y, M, D, N;

bool valid(int YY, int MM, int DD);
bool check(int YY, int MM, int DD);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> Y >> M >> D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int validcnt = 0, checkcnt = 0;
		int A, B, C;
		cin >> A >> B >> C;
		if (valid(A, B, C) == true) {
			validcnt++;
			if (check(A, B, C) == true) checkcnt++;
		}
		if (valid(C, B, A) == true) {
			validcnt++;
			if (check(C, B, A) == true) checkcnt++;
		}
		if (valid(C, A, B) == true) {
			validcnt++;
			if (check(C, A, B) == true) checkcnt++;
		}
		if (validcnt == 0) cout << "invalid\n";
		else if (checkcnt == validcnt) cout << "safe\n";
		else cout << "unsafe\n";
	}
	return 0;
}

bool valid(int YY, int MM, int DD) {
	if (MM > 12 || MM == 0) return false;
	if (MM == 1 || MM == 3 || MM == 5 || MM == 7 || MM == 8 || MM == 10 || MM == 12) {
		if (DD > 31 || DD == 0) return false;
	}
	else if (MM == 2) {
		if (YY % 4 == 0) {
			if (DD > 29 || DD == 0) return false;
		}
		else {
			if (DD > 28 || DD == 0) return false;
		}
	}
	else {
		if (DD > 30 || DD == 0) return false;
	}
	return true;
}

bool check(int YY, int MM, int DD) {
	if (YY < Y) return false;
	else if (YY > Y) return true;
	if (MM < M) return false;
	else if (MM > M) return true;
	if (DD < D) return false;
	else return true;
}