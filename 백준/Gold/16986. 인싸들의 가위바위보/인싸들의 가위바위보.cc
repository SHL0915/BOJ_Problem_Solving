#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[10][10];
int A[20], B[20];
int bt[10], mark[10];
pair<int, int> turn, cmp;

void BackTracking(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < 20; i++) cin >> A[i];
	for (int i = 0; i < 20; i++) cin >> B[i];
	BackTracking(0);
	cout << 0;
	return 0;
}

void BackTracking(int k) {
	if (k == N) {
		turn = { 0,1 };
		int pos0 = 0, pos1 = 0, pos2 = 0, win0 = 0, win1 = 0, win2 = 0;
		while (1) {
			if (win1 == K || win2 == K || win0 == K) break;
			if (turn == (cmp = { 0,1 })) {
				switch (arr[bt[pos0++]][A[pos1++]]) {
				case 0: win1++; turn = { 1,2 }; break;
				case 1: win1++; turn = { 1,2 }; break;
				case 2: win0++; turn = { 0,2 }; break;
				}
			}
			else if (turn == (cmp = { 1,2 })) {
				switch (arr[A[pos1++]][B[pos2++]]) {
				case 0: win2++; turn = { 0,2 }; break;
				case 1: win2++; turn = { 0,2 }; break;
				case 2: win1++; turn = { 0,1 }; break;
				}
			}
			else {
				switch (arr[bt[pos0++]][B[pos2++]]) {
				case 0: win2++; turn = { 1,2 }; break;
				case 1: win2++; turn = { 1,2 }; break;
				case 2: win0++; turn = { 0,1 }; break;
				}
			}
		}
		if (win0 == K) {
			cout << 1;
			exit(0);
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				bt[k] = i;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}