#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, pair<int, int>> plii;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct cmp {
	bool operator() (plii A, plii B) {
		return A.first > B.first;
	}
};

int xs, ys, xe, ye;
pair<pair<int, int>, pair<int, int>> t[3];
map <pii, vector<plii>> graph;
map <pii, long long> dis;

long long absol(long long A) {
	if (A >= 0) return A;
	else return -1 * A;
}

long long dist(long long x1, long long y1, long long x2, long long y2) {
	return absol(x1 - x2) + absol(y1 - y2);
}

void Dijkstra(int start_x, int start_y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> xs >> ys >> xe >> ye;
	dis[{xs, ys}] = INF;
	dis[{xe, ye}] = INF;
	graph[{xs, ys}].push_back({ dist(xs,ys,xe,ye),{xe,ye} });
	graph[{xe, ye}].push_back({ dist(xs,ys,xe,ye),{xs,ys} });
	for (int i = 0; i < 3; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		t[i] = { {x1,y1},{x2,y2} };
		dis[{x1, y1}] = INF;
		dis[{x2, y2}] = INF;
		graph[{xs, ys}].push_back({ dist(xs,ys,x1,y1),{x1,y1} });
		graph[{x1, y1}].push_back({ dist(xs,ys,x1,y1),{xs,ys} });
		graph[{xs, ys}].push_back({ dist(xs,ys,x2,y2),{x2,y2} });
		graph[{x2, y2}].push_back({ dist(xs,ys,x2,y2),{xs,ys} });
		graph[{x1, y1}].push_back({ 10, {x2,y2} });
		graph[{x2, y2}].push_back({ 10, {x1,y1} });
		graph[{xe, ye}].push_back({ dist(xe,ye,x1,y1),{x1,y1} });
		graph[{x1, y1}].push_back({ dist(xe,ye,x1,y1),{xe,ye} });
		graph[{xe, ye}].push_back({ dist(xe,ye,x2,y2),{x2,y2} });
		graph[{x2, y2}].push_back({ dist(xe,ye,x2,y2),{xe,ye} });
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			int x1 = t[i].first.first;
			int y1 = t[i].first.second;
			int x2 = t[i].second.first;
			int y2 = t[i].second.second;
			int x3 = t[j].first.first;
			int y3 = t[j].first.second;
			int x4 = t[j].second.first;
			int y4 = t[j].second.second;
			graph[{x1, y1}].push_back({ dist(x1,y1,x3,y3),{x3,y3} });
			graph[{x3, y3}].push_back({ dist(x1,y1,x3,y3),{x1,y1} });
			graph[{x1, y1}].push_back({ dist(x1,y1,x4,y4),{x4,y4} });
			graph[{x4, y4}].push_back({ dist(x1,y1,x4,y4),{x1,y1} });
			graph[{x2, y2}].push_back({ dist(x2,y2,x3,y3),{x3,y3} });
			graph[{x2, y2}].push_back({ dist(x2,y2,x4,y4),{x4,y4} });
			graph[{x3, y3}].push_back({ dist(x2,y2,x3,y3),{x2,y2} });
			graph[{x4, y4}].push_back({ dist(x2,y2,x4,y4),{x2,y2} });
		}
	}
	Dijkstra(xs, ys);
	cout << dis[{xe, ye}];
	return 0;
}

void Dijkstra(int start_x, int start_y) {
	priority_queue<plii, vector<plii>, cmp> pq;
	pq.push({ 0,{start_x, start_y} });
	dis[{start_x, start_y}] = 0;
	while (pq.size()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		long long val = pq.top().first;
		pq.pop();
		if (dis[{x, y}] < val) continue;
		for (int i = 0; i < graph[{x, y}].size(); i++) {
			int next_x = graph[{x, y}][i].second.first;
			int next_y = graph[{x, y}][i].second.second;
			long long new_val = val + graph[{x, y}][i].first;
			if (dis[{next_x, next_y}] > new_val) {
				dis[{next_x, next_y}] = new_val;
				pq.push({ new_val, {next_x, next_y} });
			}
		}
	}
}