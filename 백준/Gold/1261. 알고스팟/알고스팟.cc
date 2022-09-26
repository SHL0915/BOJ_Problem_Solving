#include <iostream>
#include <deque>
using namespace std;

struct dqData {
	int x, y, breadth;
};

int N, M;
int mark[100][100];
int map[100][100];
deque <dqData> q;

void BFS(void);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - '0';
			mark[i][j] = -1;
		}
	}	
	q.push_front({ 0,0,0 });
	while (q.size())
		BFS();	
	cout << mark[N - 1][M - 1];
	return 0;
}

void BFS(void) {
	int x = q.front().x;
	int y = q.front().y;
	int breadth = q.front().breadth;
	q.pop_front();
	if (mark[y][x] != -1) {
		return;
	}
	mark[y][x] = breadth;
	if (x > 0) {
		if (map[y][x - 1] == 0) {
			if (mark[y][x - 1] != -1 && mark[y][x - 1] > breadth)
				mark[y][x - 1] = breadth;
			q.push_front({ x - 1,y,breadth });
		}			
		else {
			if (mark[y][x - 1] != -1 && mark[y][x - 1] > breadth + 1)
				mark[y][x - 1] = breadth + 1;
			q.push_back({ x - 1,y,breadth + 1});
		}
	}
	if (x < M - 1) {
		if (map[y][x + 1] == 0) {
			if (mark[y][x + 1] != -1 && mark[y][x + 1] > breadth)
				mark[y][x + 1] = breadth;
			q.push_front({ x + 1,y,breadth });
		}
		else {
			if (mark[y][x + 1] != -1 && mark[y][x + 1] > breadth + 1)
				mark[y][x + 1] = breadth + 1;
			q.push_back({ x + 1,y,breadth + 1 });
		}
	}
	if (y > 0) {
		if (map[y - 1][x] == 0) {
			if (mark[y - 1][x] != -1 && mark[y - 1][x] > breadth)
				mark[y - 1][x] = breadth;
			q.push_front({ x,y - 1,breadth });
		}
		else {
			if (mark[y - 1][x] != -1 && mark[y - 1][x] > breadth + 1)
				mark[y - 1][x] = breadth + 1;
			q.push_back({ x,y - 1,breadth + 1});
		}
	}
	if (y < N - 1) {
		if (map[y + 1][x] == 0) {
			if (mark[y + 1][x] != -1 && mark[y + 1][x] > breadth)
				mark[y + 1][x] = breadth;
			q.push_front({ x,y + 1,breadth });
		}
		else {
			if (mark[y + 1][x] != -1 && mark[y + 1][x] > breadth + 1)
				mark[y + 1][x] = breadth + 1;
			q.push_back({ x,y + 1,breadth + 1 });
		}
	}	
	return;
}