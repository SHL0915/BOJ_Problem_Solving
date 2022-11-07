#include <iostream>
using namespace std;

int N, M, now;
int road[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> road[i];
	for (int i = 1; i <= N; i++) {
		if (road[i] == 1) {
			now++;
			while (i <= N) {
				if (road[i] == 0) break;
				i++;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		int task, idx;
		cin >> task;
		if (task == 0) cout << now << '\n';
		else {
			cin >> idx;
			if (road[idx] == 1) continue;
			else {
				if (idx == 1) {
					if (N == 1) now++;
					else if (road[idx + 1] == 0) now++;
				}
				else if (idx == N) {
					if (N == 1) now++;
					else if (road[idx - 1] == 0) now++;
				}
				else {
					int cnt = 0;
					if (road[idx + 1] == 1) cnt++;
					if (road[idx - 1] == 1) cnt++;
					if (cnt == 0) now++;
					else if (cnt == 2) now--;
				}
			}
			road[idx] = 1;
		}
	}
	return 0;
}