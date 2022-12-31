#include <bits/stdc++.h>
using namespace std;

string S;
int table[31][31];

int DP(int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	memset(table, -1, sizeof(table));
	cout << DP(0, S.length() - 1);
	return 0;
}

int DP(int left, int right) {
	if (left == right) return 1;
	if (right - left == 1) {
		if (S[left] == S[right]) return 3;
		else return 2;
	}
	int& ret = table[left][right];
	if (ret != -1) return ret;
	ret = DP(left + 1, right) + DP(left, right - 1) - DP(left + 1, right - 1);
	if (S[left] == S[right]) ret += (DP(left + 1, right - 1) + 1);	
	return ret;
}