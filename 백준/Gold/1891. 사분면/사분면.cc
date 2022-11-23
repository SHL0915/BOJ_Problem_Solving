#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d;
string org;
int arr[51];
ll x, y;

int DNC_X(ll delta_x, int state, int dir);
int DNC_Y(ll delta_y, int state, int dir);

ll absol(ll A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> d;
	cin >> org;
	for (int i = 0; i < d; i++) arr[i] = org[d - 1 - i] - '0';
	cin >> x >> y;
	int delta_x, delta_y;
	if (x >= 0) delta_x = DNC_X(x, d - 1, 0);
	else delta_x = DNC_X(absol(x), d - 1, 1);
	if (y >= 0) delta_y = DNC_Y(y, d - 1, 0);
	else delta_y = DNC_Y(absol(y), d - 1, 1);
	if (delta_x == 1 || delta_y == 1) cout << -1;
	else for (int i = d - 1; i >= 0; i--) cout << arr[i];
	return 0;
}

int DNC_X(ll delta_x, int state, int dir) {
	if (state == 0) {
		if (delta_x & 1) {
			if (dir == 0) {
				switch (arr[state]) {
				case 1: arr[state] = 2; return 1;
				case 2: arr[state] = 1; return 0;
				case 3: arr[state] = 4; return 0;
				case 4: arr[state] = 3; return 1;
				}
			}
			else {
				switch (arr[state]) {
				case 1: arr[state] = 2; return 0;
				case 2: arr[state] = 1; return 1;
				case 3: arr[state] = 4; return 1;
				case 4: arr[state] = 3; return 0;
				}
			}
		}
		else return 0;
	}
	else {
		int d = DNC_X(delta_x, state - 1, dir);
		if (d == 1) {
			if (delta_x & (1LL << state)) return 1;			
			else {
				if (dir == 0) {
					switch (arr[state]) {
					case 1: arr[state] = 2; return 1;
					case 2: arr[state] = 1; return 0;
					case 3: arr[state] = 4; return 0;
					case 4: arr[state] = 3; return 1;
					}
				}
				else {
					switch (arr[state]) {
					case 1: arr[state] = 2; return 0;
					case 2: arr[state] = 1; return 1;
					case 3: arr[state] = 4; return 1;
					case 4: arr[state] = 3; return 0;
					}
				}
			}
		}
		else {
			if (delta_x & (1LL << state)) {
				if (dir == 0) {
					switch (arr[state]) {
					case 1: arr[state] = 2; return 1;
					case 2: arr[state] = 1; return 0;
					case 3: arr[state] = 4; return 0;
					case 4: arr[state] = 3; return 1;
					}
				}
				else {
					switch (arr[state]) {
					case 1: arr[state] = 2; return 0;
					case 2: arr[state] = 1; return 1;
					case 3: arr[state] = 4; return 1;
					case 4: arr[state] = 3; return 0;
					}
				}
			}
			else return 0;
		}
	}
}

int DNC_Y(ll delta_y, int state, int dir) {
	if (state == 0) {
		if (delta_y & 1) {
			if (dir == 0) {
				switch (arr[state]) {
				case 1: arr[state] = 4; return 1;
				case 2: arr[state] = 3; return 1;
				case 3: arr[state] = 2; return 0;
				case 4: arr[state] = 1; return 0;
				}
			}
			else {
				switch (arr[state]) {
				case 1: arr[state] = 4; return 0;
				case 2: arr[state] = 3; return 0;
				case 3: arr[state] = 2; return 1;
				case 4: arr[state] = 1; return 1;
				}
			}
		}
		else return 0;
	}
	else {
		int d = DNC_Y(delta_y, state - 1, dir);
		if (d == 1) {
			if (delta_y & (1LL << state)) return 1;
			else {
				if (dir == 0) {
					switch (arr[state]) {
					case 1: arr[state] = 4; return 1;
					case 2: arr[state] = 3; return 1;
					case 3: arr[state] = 2; return 0;
					case 4: arr[state] = 1; return 0;
					}
				}
				else {
					switch (arr[state]) {
					case 1: arr[state] = 4; return 0;
					case 2: arr[state] = 3; return 0;
					case 3: arr[state] = 2; return 1;
					case 4: arr[state] = 1; return 1;
					}
				}
			}
		}
		else {
			if (delta_y & (1LL << state)) {
				if (dir == 0) {
					switch (arr[state]) {
					case 1: arr[state] = 4; return 1;
					case 2: arr[state] = 3; return 1;
					case 3: arr[state] = 2; return 0;
					case 4: arr[state] = 1; return 0;
					}
				}
				else {
					switch (arr[state]) {
					case 1: arr[state] = 4; return 0;
					case 2: arr[state] = 3; return 0;
					case 3: arr[state] = 2; return 1;
					case 4: arr[state] = 1; return 1;
					}
				}
			}
			else return 0;
		}
	}
}