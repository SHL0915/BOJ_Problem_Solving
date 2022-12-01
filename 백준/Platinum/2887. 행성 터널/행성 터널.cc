#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, pair<int, int>> plii;
typedef pair<pair<int, int>, pair<int, int>> piiii;

int N, cnt;
long long ans;
int parent[100001];
piiii planet[100001];
vector <plii> graph;

bool cmp_x(piiii A, piiii B) {
	return A.first.first > B.first.first;
}

bool cmp_y(piiii A, piiii B) {
	return A.first.second > B.first.second;
}

bool cmp_z(piiii A, piiii B) {
	return A.second.first > B.second.first;
}

int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i <= N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;		
		planet[i] = { {x,y},{z,i} };
	}
	sort(planet, planet + N, cmp_x);
	for (int i = 1; i < N; i++) {
		graph.push_back({ absol(planet[i].first.first - planet[i - 1].first.first), {planet[i].second.second, planet[i - 1].second.second} });
	}
	sort(planet, planet + N, cmp_y);
	for (int i = 1; i < N; i++) {
		graph.push_back({ absol(planet[i].first.second - planet[i - 1].first.second), {planet[i].second.second, planet[i - 1].second.second} });
	}
	sort(planet, planet + N, cmp_z);
	for (int i = 1; i < N; i++) {
		graph.push_back({ absol(planet[i].second.first - planet[i - 1].second.first), {planet[i].second.second, planet[i - 1].second.second} });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == N - 1) break;
		int A = Find(graph[i].second.first);
		int B = Find(graph[i].second.second);
		if (A == B) continue;
		Union(A, B);
		ans += graph[i].first;
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
	if (A > B) parent[A] = B;
	else parent[B] = A;
	return;
}