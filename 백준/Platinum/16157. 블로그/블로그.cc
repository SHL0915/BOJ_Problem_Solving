#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
string S;
int arr[101];
int table[101][101][4];

int DP(int left, int right, int color);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') arr[i] = 0;
		else if (S[i] == 'G') arr[i] = 1;
		else arr[i] = 2;
	}
	memset(table, -1, sizeof(table));	
	cout << DP(0, N - 1, 3);
	return 0;
}

int DP(int left, int right, int color) {
	if (left > right) return 0;
	if (left == right) return (arr[left] != color);
	int& ret = table[left][right][color];
	if (ret != -1) return ret;
	ret = INF;
	int a = (arr[left] != color);
	ret = min(ret, a + DP(left + 1, right, color));	
	for (int i = left; i <= right; i++) ret = min(ret, 1 + DP(left, i, arr[left]) + DP(i + 1, right, color));
	return ret;
}