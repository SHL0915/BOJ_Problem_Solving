#include <iostream>
#include <queue>
using namespace std;

int N, k;
string map[2];
int mark[100000][2];
queue <pair<pair <int, int>, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> k;
	cin >> map[0] >> map[1];
	for (int i = 0; i < N; i++) {
		if (map[0][i] == '0') mark[i][0] = 1;
		if (map[1][i] == '0') mark[i][1] = 1;
	}
	q.push({ { 0,0 }, 1 });
	while (q.size()) BFS();
	cout << 0;
	return 0;
}

void BFS() {
	pair <pair <int, int>, int> temp = q.front();
	q.pop();
	if (temp.first.first > N - 1) {
		cout << 1;
		exit(0);
	}
	if (temp.first.first < temp.second - 1) return;
	if (mark[temp.first.first][temp.first.second] != 0) return;
	mark[temp.first.first][temp.first.second] = temp.second;
	q.push({ {temp.first.first + 1, temp.first.second}, temp.second + 1 });
	q.push({ {temp.first.first - 1, temp.first.second}, temp.second + 1 });
	q.push({ {temp.first.first + k, (temp.first.second + 1) % 2}, temp.second + 1 });
	return;
}