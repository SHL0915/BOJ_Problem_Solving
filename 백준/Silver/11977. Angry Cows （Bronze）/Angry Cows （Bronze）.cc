#include <bits/stdc++.h>
using namespace std;

int N, ans, t, cnt;
int arr[101];
int mark[101];
queue <int> q, cand;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		t = 0;
		cnt = 0;
		memset(mark, 0, sizeof(mark));
		q.push(i);
		while (q.size()) {
			t++;
			while (q.size()) BFS();
			while (cand.size()) {
				q.push(cand.front());
				cand.pop();
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}

void BFS() {
	int now = q.front();
	q.pop();
	if (mark[now] != 0) return;
	mark[now] = 1;
	cnt++;
	for (int i = now + 1; i < N; i++) if (arr[i] - arr[now] <= t) cand.push(i);
	for (int i = now - 1; i >= 0; i--) if (arr[now] - arr[i] <= t) cand.push(i);
	return;	
}