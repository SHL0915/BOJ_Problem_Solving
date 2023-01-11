#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, K;
int even_mark[500001];
int odd_mark[500001];
queue <pii> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	q.push({ N, 0 });
	memset(even_mark, -1, sizeof(even_mark));
	memset(odd_mark, -1, sizeof(odd_mark));
	while (q.size()) BFS();
	for (int i = 0; ; i++) {
		int now = K + i * (i + 1) / 2;
		if (now > 500000) break;
		if (i % 2 && odd_mark[now] != -1 && odd_mark[now] <= i) {
			cout << i;
			return 0;
		}
		else if (i % 2 == 0 && even_mark[now] != -1 && even_mark[now] <= i) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}

void BFS() {
	pii f = q.front();
	q.pop();
	int now = f.first;
	int d = f.second;
	if (now < 0 || now > 500000) return;
	if (K + d * (d + 1) / 2 > 500000) return;
	if (d % 2 && odd_mark[now] != -1) return;
	if (d % 2 == 0 && even_mark[now] != -1) return;
	if (d % 2) odd_mark[now] = d;
	else even_mark[now] = d;
	if (now <= 250000) q.push({ now * 2, d + 1 });
	if (now > 0) q.push({ now - 1, d + 1 });
	if (now < 500000) q.push({ now + 1, d + 1 });
	return;
}