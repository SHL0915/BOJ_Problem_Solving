#include <bits/stdc++.h>
using namespace std;

int N;
int arr[3];
int table[61][61][61];

int DP(int A, int B, int C);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];	
	cout << DP(arr[0], arr[1], arr[2]);
	return 0;
}

int DP(int A, int B, int C) {
	A = max(A, 0);
	B = max(B, 0);
	C = max(C, 0);
	if (A == 0 && B == 0 && C == 0) return 0;
	else if (table[A][B][C] != 0) return table[A][B][C];
	int temp1 = min(DP(A - 9, B - 3, C - 1) + 1, DP(A - 9, B - 1, C - 3) + 1);
	int temp2 = min(DP(A - 3, B - 9, C - 1) + 1, DP(A - 1, B - 9, C - 3) + 1);
	int temp3 = min(DP(A - 1, B - 3, C - 9) + 1, DP(A - 3, B - 1, C - 9) + 1);
	temp1 = min(temp1, temp2);
	temp1 = min(temp1, temp3);
	table[A][B][C] = temp1;
	return table[A][B][C];
}