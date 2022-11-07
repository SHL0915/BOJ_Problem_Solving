#include <iostream>
#include <queue>
using namespace std;

int N, a, b;
int mark[1000001];
queue <pair<int, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> a >> b;
	q.push({ N,0 });
	while (q.size()) BFS();
	return 0;
}

void BFS() {
	pair<int, int> temp = q.front();
	q.pop();
	if (temp.first < 0) return;
	if (mark[temp.first] != 0) return;
	if (temp.first == 0) {
		cout << temp.second;
		exit(0);
	}
	mark[temp.first] = 1;
	q.push({ temp.first - 1, temp.second + 1 });
	q.push({ temp.first - 1 - a, temp.second + 1 });
	q.push({ temp.first - 1 - b, temp.second + 1 });
	return;
}