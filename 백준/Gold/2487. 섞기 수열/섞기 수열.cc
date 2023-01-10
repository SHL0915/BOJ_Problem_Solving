#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[20001];
int parent[20001];
int sz[20001];
vector <pair<int, int>> graph;
vector <int> num;

int Find(int a);
void Union(int a, int b);
long long GCD(long long a, long long b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
		cin >> arr[i];
		graph.push_back({ i, arr[i] });
	}
	for (int i = 0; i < graph.size(); i++) {
		int a = graph[i].first;
		int b = graph[i].second;
		if (Find(a) == Find(b)) continue;
		else Union(a, b);
	}
	for (int i = 1; i <= N; i++) if (sz[Find(i)] != 1) num.push_back(sz[Find(i)]);
	if (num.size() == 0) {
		cout << 1;
		return 0;
	}
	long long now = num[0];
	for (int i = 1; i < num.size(); i++) {
		long long gcd = GCD(now, (long long)num[i]);
		now = gcd * (now / gcd) * (num[i] / gcd);
	}
	cout << now;
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
	if (a > b) {
		parent[a] = b;
		sz[b] += sz[a];
	}
	else {
		parent[b] = a;
		sz[a] += sz[b];
	}
	return;
}

long long GCD(long long a, long long b) {
	if (a > b) {
		if (a % b == 0) return b;
		else return GCD(a % b, b);
	}
	else {
		if (b % a == 0) return a;
		else return GCD(b % a, a);
	}
}