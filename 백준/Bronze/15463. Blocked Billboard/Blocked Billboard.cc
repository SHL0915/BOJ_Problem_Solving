#include <bits/stdc++.h>
using namespace std;

int ans;
int arr[2005][2005];

void paint(int color);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 2; i++) paint(1);
	paint(0);
	for (int i = 0; i < 2005; i++) {
		for (int j = 0; j < 2005; j++) ans += arr[i][j];
	}
	cout << ans;
	return 0;
}

void paint(int color) {
	pair<int, int> ll, ur;
	cin >> ll.first >> ll.second >> ur.first >> ur.second;
	ll.first += 1000, ll.second += 1000, ur.first += 1000, ur.second += 1000;
	for (int j = ll.second; j < ur.second; j++) {
		for (int k = ll.first; k < ur.first; k++) arr[j][k] = color;
	}
	return;
}