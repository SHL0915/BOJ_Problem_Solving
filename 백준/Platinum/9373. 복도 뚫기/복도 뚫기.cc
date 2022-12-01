#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, pair<int, int>> pdii;
typedef pair<pair<int, int>, int> piii;

int T, W, N, cnt;
double ans;
int parent[1002];
piii sensor[1001];
vector<pdii> graph;

int Find(int node);
void Union(int A, int B);
double dist(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	cin >> T;
	while (T--) {
		cin >> W >> N;
		if (N == 0) {
			cout << (double)W / 2 << '\n';
			continue;
		}
		for (int i = 0; i <= N + 1; i++) parent[i] = i;
		graph.clear();
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			sensor[i] = { {x,y},r };
		}
		for (int i = 1; i <= N; i++) {
			graph.push_back({ max((double)(sensor[i].first.first - sensor[i].second), (double)0), {0,i} });
			graph.push_back({ max((double)(W - sensor[i].first.first - sensor[i].second), (double)0) ,{i,N + 1} });
			for (int j = i + 1; j <= N; j++) {
				double d = dist(sensor[i].first.first, sensor[i].first.second, sensor[i].second, sensor[j].first.first, sensor[j].first.second, sensor[j].second);
				graph.push_back({ d,{i,j} });
			}
		}
		sort(graph.begin(), graph.end());		
		for (int i = 0; i < graph.size(); i++) {
			if (cnt == N + 1) break;
			int A = Find(graph[i].second.first);
			int B = Find(graph[i].second.second);
			if (A == B) continue;
			Union(A, B);
			cnt++;
			if (Find(0) == Find(N + 1)) {
				ans = graph[i].first / 2;
				break;
			}
		}
		cout << ans << '\n';
	}
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

double dist(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2) {
	ll temp = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	double ret = sqrt(temp);
	ret -= (r1 + r2);
	return max(ret, (double)0);
}