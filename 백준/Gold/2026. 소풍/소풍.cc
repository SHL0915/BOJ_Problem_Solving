#include <bits/stdc++.h>
using namespace std;

int K, N, F;
int bt[901];
int mark[901];
int graph[901][901];

void BackTracking(int now, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> K >> N >> F;
	for (int i = 0; i < F; i++) {
		int A, B;
		cin >> A >> B;
		graph[A][B] = 1;
		graph[B][A] = 1;
	}
	BackTracking(1, 0);
	cout << -1;
	return 0;
}

void BackTracking(int now, int k) {
	if (k == K) {
		for (int i = 0; i < k; i++) cout << bt[i] << '\n';
		exit(0);
	}
	else {
		for (int i = now; i <= N; i++) {
			int flag = 0;
			for (int j = 0; j < k; j++) {
				if (graph[i][bt[j]] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) continue;
			bt[k] = i;
			BackTracking(i + 1, k + 1);
		}
	}
}