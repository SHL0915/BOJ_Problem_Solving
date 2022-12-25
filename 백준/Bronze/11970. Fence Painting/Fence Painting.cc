#include <bits/stdc++.h>
using namespace std;

pair <int, int> arr[2];
int mark[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 2; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = arr[0].first; i < arr[0].second; i++) mark[i] = 1;
	for (int i = arr[1].first; i < arr[1].second; i++) mark[i] = 1;
	int cnt = 0;
	for (int i = 0; i <= 100; i++) if (mark[i] == 1) cnt++;
	cout << cnt;
	return 0;
}