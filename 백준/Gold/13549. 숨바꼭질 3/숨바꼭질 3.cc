#include <iostream>
#include <queue>
using namespace std;

int N, K;
int mark[200001] = { 0 };
queue <pair<int, int>> q;

void BFS(void);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	q.push({ N,0 });
	while (q.size())
		BFS();
	return 0;
}

void BFS(void) {
	int pos = q.front().first;
	int time = q.front().second;
	if (pos == K) {
		cout << time;
		exit(0);
	}
	q.pop();
	if (mark[pos] != 0)
		return;
	mark[pos] = 1;
	if (pos <= 100000)
		q.push({ pos * 2, time });
	if (pos > 0)
		q.push({ pos - 1,time + 1 });
	if (pos < 200000)
		q.push({ pos + 1,time + 1 });
	return;
}