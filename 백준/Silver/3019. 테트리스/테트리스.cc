#include <bits/stdc++.h>
using namespace std;

int C, P, ans;
int arr[100];

int check(int x, int block, int dir);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> P;
	for (int i = 0; i < C; i++) cin >> arr[i];
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < 4; j++) {
			ans += check(i, P, j);
		}
	}
	if (P == 1 || P == 3 || P == 4) ans /= 2;
	else if (P == 2) ans /= 4;
	cout << ans;
	return 0;
}

int check(int x, int block, int dir) {
	if (block == 1) {
		if (dir == 0 || dir == 2) return 1;
		else {
			if (x > C - 4) return 0;
			else {
				for (int i = 0; i < 4; i++) {
					if (arr[x + i] != arr[x]) return 0;
				}
				return 1;
			}
		}		
	}
	else if (block == 2) {
		if (x > C - 2) return 0;
		else {
			for (int i = 0; i < 2; i++) {
				if (arr[x + i] != arr[x]) return 0;
			}
			return 1;
		}
	}
	else if (block == 3) {
		if (dir == 0 || dir == 2) {
			if (x > C - 3) return 0;
			else {
				if (arr[x] == arr[x + 1] && arr[x + 2] == arr[x + 1] + 1) return 1;
				else return 0;
			}
		}
		else {
			if (x > C - 2) return 0;
			else {
				if (arr[x] == arr[x + 1] + 1) return 1;
				else return 0;
			}
		}		
	}
	else if (block == 4) {
		if (dir == 0 || dir == 2) {
			if (x > C - 3) return 0;
			else {
				if (arr[x + 1] == arr[x + 2] && arr[x] == arr[x + 1] + 1) return 1;
				else return 0;
			}
		}
		else {
			if (x > C - 2) return 0;
			else {
				if (arr[x + 1] == arr[x] + 1) return 1;
				else return 0;
			}
		}
	}
	else if (block == 5) {
		if (dir == 0) {
			if (x > C - 3) return 0;
			else {
				if (arr[x] == arr[x + 1] && arr[x + 1] == arr[x + 2]) return 1;
				else return 0;
			}
		}
		else if (dir == 1) {
			if (x > C - 2) return 0;
			else {
				if (arr[x + 1] == arr[x] + 1) return 1;
				else return 0;
			}
		}
		else if (dir == 2) {
			if (x > C - 3) return 0;
			else {
				if (arr[x] == arr[x + 2] && arr[x] == arr[x + 1] + 1) return 1;
				else return 0;
			}
		}
		else {
			if (x > C - 2) return 0;
			else {
				if (arr[x] == arr[x + 1] + 1) return 1;
				else return 0;
			}
		}
	}
	else if (block == 6) {
		if (dir == 0) {
			if (x > C - 3) return 0;
			else {
				if (arr[x] == arr[x + 1] && arr[x + 1] == arr[x + 2]) return 1;
				else return 0;
			}
		}
		else if (dir == 1) {
			if (x > C - 2) return 0;
			else {
				if (arr[x] == arr[x + 1]) return 1;
				else return 0;
			}
		}
		else if (dir == 2) {
			if (x > C - 3) return 0;
			else {
				if (arr[x + 1] == arr[x + 2] && arr[x] == arr[x + 1] - 1) return 1;
				else return 0;
			}
		}
		else {
			if (x > C - 2) return 0;
			else {
				if (arr[x] == arr[x + 1] + 2) return 1;
				else return 0;
			}
		}
	}
	else {
		if (dir == 0) {
			if (x > C - 3) return 0;
			else {
				if (arr[x] == arr[x + 1] && arr[x + 1] == arr[x + 2]) return 1;
				else return 0;
			}
		}
		else if (dir == 1) {
			if (x > C - 2) return 0;
			else {
				if (arr[x] == arr[x + 1] - 2) return 1;
				else return 0;
			}
		}
		else if (dir == 2) {
			if (x > C - 3) return 0;
			else {
				if (arr[x] == arr[x + 1] && arr[x] == arr[x + 2] + 1) return 1;
				else return 0;
			}
		}
		else {
			if (x > C - 2) return 0;
			else {
				if (arr[x] == arr[x + 1]) return 1;
				else return 0;
			}
		}
	}
}