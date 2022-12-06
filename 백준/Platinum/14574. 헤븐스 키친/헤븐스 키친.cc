#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int>> plii;

int N, cnt;
ll ans;
pair<ll, ll> arr[1001];
vector <plii> graph;
vector <int> tree[1001];
int parent[1001];
vector <pair<int, int>> vans;

bool cmp(plii A, plii B) {
	return A.first > B.first;
}

ll absol(ll A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int Find(int node);
void Union(int A, int B);
void DFS(int node, int par);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		ll A, B;
		cin >> A >> B;
		arr[i] = { A,B };
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			graph.push_back({ (arr[i].second + arr[j].second) / absol(arr[i].first - arr[j].first),{i,j} });
		}
	}
	sort(graph.begin(), graph.end(), cmp);
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == N - 1) break;
		int A = Find(graph[i].second.first);
		int B = Find(graph[i].second.second);
		if (A == B) continue;
		Union(A, B);
		tree[graph[i].second.first].push_back(graph[i].second.second);
		tree[graph[i].second.second].push_back(graph[i].second.first);
		ans += graph[i].first;
		cnt++;
	}
	cout << ans << '\n';
	DFS(1, 0);
	for (int i = 0; i < vans.size(); i++) cout << vans[i].first << " " << vans[i].second << '\n';
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
	if (A > B) parent[A] = B;
	else parent[B] = A;
	return;
}

void DFS(int node, int par) {
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == par) continue;
		DFS(tree[node][i], node);
	}
	if (par != 0) vans.push_back({ par,node });
}