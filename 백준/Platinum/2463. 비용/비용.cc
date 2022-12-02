#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;
const long long mod = 1000000000;

int N, M, cnt, pcnt;
long long ans;
vector <piii> graph;
int parent[100001];
pair<long long, long long> num[100001];
long long psum[100001];
long long cost[100001];

bool cmp(piii A, piii B) {
	return A.first > B.first;
}

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		num[i] = {1,0};
	}
	for (int i = 0; i < M; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		graph.push_back({ w,{x,y} });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		cost[i] = graph[i].first;
		if (i == 0) psum[i] = cost[i];
		else psum[i] = psum[i - 1] + cost[i];
	}
	sort(graph.begin(), graph.end(), cmp);
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == N - 1) break;
		int A = Find(graph[i].second.first);
		int B = Find(graph[i].second.second);
		if (A == B) continue;
		Union(A, B);
		long long n = num[min(Find(A), Find(B))].first;
		long long pcnt = num[min(Find(A), Find(B))].second;
		ans += psum[lower_bound(cost, cost + M, graph[i].first) - cost] * ((n * (n - 1)) / 2 - pcnt);
		ans = ans % mod;
		num[min(Find(A), Find(B))].second = n * (n - 1) / 2;
		cnt++;
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
		num[B].first += num[A].first;
		num[B].second += num[A].second;
	}
	else {
		parent[B] = A;
		num[A].first += num[B].first;
		num[A].second += num[B].second;
	}
	return;
}