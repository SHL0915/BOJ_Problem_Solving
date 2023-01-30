#include <bits/stdc++.h>
using namespace std;

string S;
int arr[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	for (int i = 0; i < S.length(); i++) arr[i] = S[i] - '0';
	sort(arr, arr + S.length());
	if (arr[0] != 0) {
		cout << -1;
		return 0;
	}
	int sum = 0;
	for (int i = 1; i < S.length(); i++) sum += arr[i];
	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}
	for (int i = S.length() - 1; i >= 0; i--) cout << arr[i];
	return 0;
}