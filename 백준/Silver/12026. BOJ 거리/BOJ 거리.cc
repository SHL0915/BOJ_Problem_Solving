#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;

struct cmp {
	bool operator() (piii A, piii B) {
		return A.first > B.first;
	}
};

int N;
string street;
int mark[1000];
priority_queue <piii, vector<piii>, cmp> pq;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> street;
	memset(mark, -1, sizeof(mark));
	pq.push({ 0,{0,0} });
	while (pq.size()) BFS();
	cout << mark[N - 1];
	return 0;
}

void BFS() {
	piii t = pq.top();
	pq.pop();
	int cost = t.first;
	int now = t.second.first;
	int type = t.second.second;
	if (mark[now] != -1) return;
	mark[now] = cost;
	for (int i = now + 1; i < N; i++) {
		switch (type) {
		case 0: {
			if (street[i] == 'O') pq.push({ cost + (i - now) * (i - now), {i,1} });
			break;
		}
		case 1: {
			if (street[i] == 'J') pq.push({ cost + (i - now) * (i - now), {i,2} });
			break;
		}
		case 2: {
			if (street[i] == 'B') pq.push({ cost + (i - now) * (i - now), {i,0} });
			break;
		}
		}
	}
}