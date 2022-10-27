#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
pair <int, int> s_pos, e_pos;
int mark[200][200];
queue <pair<pair<int, int>, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	s_pos = { r1,c1 };
	e_pos = { r2,c2 };
	q.push({ s_pos, 1 });
	while (q.size()) BFS();	
	cout << mark[e_pos.second][e_pos.first] - 1;
	return 0;
}

void BFS() {
	pair<pair<int, int>, int> temp = q.front();
	q.pop();
	if (temp.first.first < 0 || temp.first.second < 0 || temp.first.first >= N || temp.first.second >= N) return;	
	if (mark[temp.first.second][temp.first.first] != 0) return;
	mark[temp.first.second][temp.first.first] = temp.second;	
	q.push({ {temp.first.first - 2, temp.first.second - 1},temp.second + 1 });
	q.push({ {temp.first.first - 2, temp.first.second + 1},temp.second + 1 });
	q.push({ {temp.first.first + 2, temp.first.second - 1},temp.second + 1 });
	q.push({ {temp.first.first + 2, temp.first.second + 1},temp.second + 1 });
	q.push({ {temp.first.first, temp.first.second - 2},temp.second + 1 });
	q.push({ {temp.first.first, temp.first.second + 2},temp.second + 1 });
	return;
}