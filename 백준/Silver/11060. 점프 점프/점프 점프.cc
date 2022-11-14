#include <iostream>
#include <queue>
using namespace std;

int N;
int map[1000];
int mark[1000];
queue <pair<int, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i];
	q.push({ 0,1 });
	while (q.size()) BFS();
	cout << mark[N - 1] - 1;
	return 0;
}

void BFS() {
	pair<int, int> f = q.front();
	q.pop();
	int now = f.first;
	int d = f.second;
	if (now >= N) return;
	if (mark[now] != 0) return;
	mark[now] = d;
	for (int i = 1; i <= map[now]; i++) q.push({ now + i, d + 1 });
	return;
}