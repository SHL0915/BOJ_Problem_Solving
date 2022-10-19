#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ans, cnt, flag;
int space[50][50];
queue <pair<pair<int, int>, int>> q;

void BFS(int mark[50][50]);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> space[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (space[i][j] == 0) {
				int mark[50][50] = { 0 };
				cnt = 0;
				flag = 0;
				q.push({ {j,i},1 });
				while (q.size()) BFS(mark);			
				ans = max(ans, cnt - 1);
			}
		}
	}
	cout << ans;
	return 0;
}

void BFS(int mark[50][50]) {
	pair <pair<int, int>, int> temp = q.front();
	q.pop();
	if (flag == 1) return;
	if (temp.first.first < 0 || temp.first.second < 0 || temp.first.first > M - 1 || temp.first.second > N - 1) return;
	if (mark[temp.first.second][temp.first.first] != 0) return;
	mark[temp.first.second][temp.first.first] = temp.second + 1;
	if (space[temp.first.second][temp.first.first] == 1) {
		cnt = temp.second;
		flag = 1;
		return;
	}
	q.push({ { temp.first.first - 1, temp.first.second - 1 }, temp.second + 1 });
	q.push({ { temp.first.first - 1, temp.first.second }, temp.second + 1 });
	q.push({ { temp.first.first - 1, temp.first.second + 1 }, temp.second + 1 });
	q.push({ { temp.first.first + 1, temp.first.second - 1 }, temp.second + 1 });
	q.push({ { temp.first.first + 1, temp.first.second }, temp.second + 1 });
	q.push({ { temp.first.first + 1, temp.first.second + 1 }, temp.second + 1 });
	q.push({ { temp.first.first, temp.first.second - 1 }, temp.second + 1 });
	q.push({ { temp.first.first, temp.first.second + 1 }, temp.second + 1 });
	return;
}