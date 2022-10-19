//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

long long N, ans;
long long arr[100000];

void recur(int s, int e);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		arr[i] -= t;
	}
	recur(0, N - 1);
	cout << ans;
	return 0;
}

void recur(int s, int e) {
	while (s <= e) {
		if (arr[s] == 0) s++;
		else if (arr[e] == 0) e--;
		else if (arr[s] > 0 && arr[e] > 0) {
			int temp = min(arr[s], arr[e]);
			ans += temp;
			for (int i = s; i <= e; i++) arr[i] -= temp;			
		}
		else if (arr[s] < 0 && arr[e] < 0) {
			int temp = max(arr[s], arr[e]);
			ans -= temp;
			for (int i = s; i <= e; i++) arr[i] -= temp;
		}
		else {
			if (arr[s] > 0) {
				for (int i = s; i <= e; i++) {
					if (arr[i] < 0) {
						recur(s, i - 1);
						s = i;
						break;
					}
				}
			}
			else {
				for (int i = s; i <= e; i++) {
					if (arr[i] > 0) {
						recur(s, i - 1);
						s = i;
						break;
					}
				}
			}
		}
	}
	return;
}