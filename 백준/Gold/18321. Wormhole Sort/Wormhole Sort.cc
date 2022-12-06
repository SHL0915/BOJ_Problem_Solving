#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;

int N, M, cnt, ans = 1234567890;
int arr[100001];
int parent[100001];
int sz[100001];
set <int> unsorted;
vector <piii> graph;

bool cmp(piii A, piii B){
	return A.first > B.first;
}

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		parent[i] = i;
		if (arr[i] != i) {
			unsorted.insert(i);
			sz[i] = 1;
			cnt++;
		}
	}
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph.push_back({ C,{A,B} });
	}
	if (cnt == 0) {
		cout << -1;
		return 0;
	}
	sort(graph.begin(), graph.end(), cmp);
	for (int i = 0; i < graph.size(); i++) {
		int A = Find(graph[i].second.first);
		int B = Find(graph[i].second.second);
		if (A == B) continue;
		Union(A, B);
		ans = min(ans, graph[i].first);
		if (sz[Find(A)] == cnt) break;
	}
	cout << ans;
	return 0;
}

int Find(int node) {
	if (parent[node] == node) return parent[node];
	else return parent[node] = Find(parent[node]);
}

void Union(int A, int B) {
	A = Find(A);
	B = Find(B);
	if (A == B) return;
	if (A > B) {
		parent[A] = B;
		sz[B] += sz[A];
	}
	else {
		parent[B] = A;
		sz[A] += sz[B];
	}
	return;
}