#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int mark[1000001];
queue <pair<int, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> F >> S >> G >> U >> D;
	for (int i = 1; i <= F; i++) mark[i] = -1;
	q.push({ S,0 });
	while (q.size()) BFS();
	cout << "use the stairs";
	return 0;
}

void BFS() {
	pair<int, int> temp = q.front();
	q.pop();
	if (temp.first > F || temp.first < 1) return;
	if (temp.first == G) {
		cout << temp.second;
		exit(0);
	}
	if (mark[temp.first] != -1) return;
	mark[temp.first] = 1;
	q.push({ temp.first + U, temp.second + 1 });
	q.push({ temp.first - D, temp.second + 1 });
	return;
}