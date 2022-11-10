#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000000;

int N, K, cnt, depth = INF;
queue <pair<pair<int,int>, int>> q;
int mark[150002][2];

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= 150000; i++) mark[i][1] = INF;
	cin >> N >> K;
	mark[150001][0] = 1;
	q.push({ {N, 0}, 150001 });
	while (q.size()) BFS();
	cout << depth << '\n' << cnt;
	return 0;
}

void BFS() {
	pair<pair<int, int>, int> f = q.front();
	q.pop();
	int now = f.first.first;
	int d = f.first.second;
	int prev = f.second;
	if (now < 0 || now > 150000) return;
	if (d > depth) return;	
	if (now == K) {
		cnt += mark[prev][0];
		depth = d;
	}
	if (mark[now][1] == d) {
		mark[now][0] += mark[prev][0];
		return;
	}
	else if (mark[now][1] < d) return;
	mark[now][0] += mark[prev][0];
	mark[now][1] = min(mark[now][1], d);
	q.push({ { now + 1, d + 1 } , now });
	q.push({ { now - 1, d + 1 } , now });
	q.push({ { now * 2, d + 1 } , now });
	return;
}