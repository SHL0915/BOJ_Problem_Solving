#include <bits/stdc++.h>
using namespace std;
typedef pair<double, pair<int, int>> pdii;

int N, cnt;
double ans;
pair<double, double> stars[101];
int parent[101];
vector <pdii> graph;

double dist(double x1, double y1, double x2, double y2);
int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(5);
	cin >> N;
	for (int i = 0; i <= N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		stars[i] = { x,y };
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double d = dist(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
			graph.push_back({ d,{i,j} });
		}
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

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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