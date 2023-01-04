#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[20][20];
int graph[20][20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == k || j == k) continue;
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					cout << -1;
					return 0;
				}
				if (arr[i][j] == arr[i][k] + arr[k][j]) graph[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] != -1) ans += arr[i][j];			
		}
	}
	cout << ans / 2;
	return 0;
}