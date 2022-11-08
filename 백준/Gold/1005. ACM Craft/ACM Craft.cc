#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, N, K, W, ans;
int building[1001];
vector <int> graph[1001];
int check[1001];
int mark[1001];
queue <pair<int, int>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> building[i];
			graph[i].clear();
			mark[i] = -1;
			check[i] = 0;
		}
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			graph[X].push_back(Y);
			check[Y]++;
		}
		cin >> W;
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {
				check[i]++;
				q.push({ i, 0 });
			}
		}
		while (q.size()) BFS();
		cout << mark[W] << '\n';
	}
	return 0;
}

void BFS() {
	pair<int, int> temp = q.front();
	q.pop();
	int now = temp.first;
	int val = temp.second;
	mark[now] = max(mark[now], building[now] + val);
	check[now]--;
	if (check[now] == 0) {
		for (int i = 0; i < graph[now].size(); i++) q.push({ graph[now][i], mark[now] });
	}
}