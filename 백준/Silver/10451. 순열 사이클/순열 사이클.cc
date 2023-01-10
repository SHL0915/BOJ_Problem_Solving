#include <bits/stdc++.h>
using namespace std;

int T, N;
int arr[1001];
int parent[1001];
vector <pair<int, int>> graph;

int Find(int a);
void Union(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int cnt = 0;
		graph.clear();
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			parent[i] = i;
		}
		for (int i = 1; i <= N; i++) graph.push_back({ i, arr[i] });
		for (int i = 0; i < graph.size(); i++) {
			int a = graph[i].first;
			int b = graph[i].second;
			if (Find(a) == Find(b)) cnt++;
			else Union(a, b);
		}
		cout << cnt << '\n';
	}
	return 0;
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}