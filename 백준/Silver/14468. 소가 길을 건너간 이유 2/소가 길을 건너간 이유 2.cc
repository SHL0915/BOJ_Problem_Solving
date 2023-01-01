#include <bits/stdc++.h>
using namespace std;

int cnt;
string S;
vector <int> arr[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	for (int i = 0; i < S.length(); i++) arr[S[i] - 'A'].push_back(i);
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (i == j) continue;
			if (arr[j][0] > arr[i][0] && arr[j][0] < arr[i][1] && arr[j][1] > arr[i][1]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}