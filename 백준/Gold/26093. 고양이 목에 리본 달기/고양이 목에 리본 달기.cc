#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[101][10001];
priority_queue <pair<int, int>> table[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) cin >> arr[i][j];
	}
	for (int i = 1; i <= K; i++) table[1].push({arr[1][i], i});
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			pair<int, int> top = table[i - 1].top();
			if (top.second == j) {
				table[i - 1].pop();
				pair<int, int> sec = table[i - 1].top();
				table[i].push({ sec.first + arr[i][j], j });
				table[i - 1].push(top);
			}
			else table[i].push({ top.first + arr[i][j], j });			
		}
	}
	cout << table[N].top().first;
	return 0;
}