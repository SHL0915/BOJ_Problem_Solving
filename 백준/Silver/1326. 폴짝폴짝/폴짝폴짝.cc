#include <iostream>
#include <queue>
using namespace std;

int N, a, b, flag;
int bridge[10000];
int mark[10000];
queue <pair<int, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i <= 10000; i++) mark[i] = -1;
	for (int i = 0; i < N; i++) cin >> bridge[i];
	cin >> a >> b;
	q.push({ a - 1,0 });
	while (q.size()) BFS();
	cout << mark[b - 1];
	return 0;
}

void BFS() {
	pair <int, int> temp = q.front();
	q.pop();
	if (flag == 1) return;
	if (mark[temp.first] != -1) return;
	mark[temp.first] = temp.second;
	if (temp.first == b - 1) {
		flag = 1;
		return;
	}
	for (int i = 1; ; i++) {
		if (temp.first + bridge[temp.first] * i >= N) break;
		q.push({ temp.first + bridge[temp.first] * i , temp.second + 1 });
	}
	for (int i = 1; ; i++) {
		if (temp.first - bridge[temp.first] * i < 0) break;
		q.push({ temp.first - bridge[temp.first] * i , temp.second + 1 });
	}
	return;
}