#include <bits/stdc++.h>
using namespace std;
const int MAX = 500001;
int a, b;

/*	1. SCC로 사이클 묶어서 새로운 그래프 만들기
	2. 새로운 그래프를 위상정렬하기
	3. DP로 최대값 탐색
*/

int N, M, S, P, id, n_N;
vector <int> graph[MAX], n_graph[MAX];
long long table[MAX], n_arr[MAX];
int arr[MAX], parent[MAX], mark[MAX], scc[MAX], in_degree[MAX], rest[MAX], topsorted[MAX];
vector <vector<int>> SCC;
stack <int> s;
queue <int> q;

int DFS(int node);
void TopSort();
bool cmp(int A, int B) {
	return topsorted[A] < topsorted[B];
}
long long DP(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}	
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) if (parent[i] == 0) DFS(i);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (scc[i] != scc[next]) {
				n_graph[scc[i]].push_back(scc[next]);
				in_degree[scc[next]]++;
			}
		}
	}
	n_N = SCC.size();
	TopSort();	
	for (int i = 0; i < n_N; i++) sort(n_graph[i].begin(), n_graph[i].end(), cmp);
	cin >> S >> P;
	for (int i = 0; i < P; i++) {
		cin >> a;
		rest[scc[a]] = 1;
	}
	memset(table, -1, sizeof(table));
	cout << DP(scc[S]);
	return 0;
}

int DFS(int node) {
	parent[node] = ++id;
	s.push(node);
	int ret = parent[node];
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (parent[next] == 0) ret = min(ret, DFS(next));
		if (mark[next] == 0) ret = min(ret, parent[next]);
	}
	if (ret == parent[node]) {
		vector <int> v;
		long long sum = 0;
		while (1) {
			int t = s.top();
			s.pop();
			v.push_back(t);
			mark[t] = 1;
			scc[t] = SCC.size();
			sum += arr[t];
			if (t == node) break;
		}
		n_arr[SCC.size()] = sum;
		SCC.push_back(v);
	}
	return ret;
}

void TopSort() {
	vector <int> sorted;
	for (int i = 0; i < n_N; i++) if (in_degree[i] == 0) q.push(i);
	for (int i = 0; i < n_N; i++) {
		int now = q.front();
		q.pop();
		sorted.push_back(now);
		for (int j = 0; j < n_graph[now].size(); j++) {
			int next = n_graph[now][j];
			if (--in_degree[next] == 0) q.push(next);
		}
	}
	for (int i = 0; i < sorted.size(); i++) topsorted[sorted[i]] = i;
	return;
}

long long DP(int node) {
	long long& ret = table[node];
	if (ret != -1) return ret;
	ret = 0;
	long long temp = 0;
	for (int i = 0; i < n_graph[node].size(); i++) temp = max(temp, DP(n_graph[node][i]));		
	ret = n_arr[node] + temp;
	if (temp == 0 && rest[node] == 0) ret = 0;
	return ret;
}