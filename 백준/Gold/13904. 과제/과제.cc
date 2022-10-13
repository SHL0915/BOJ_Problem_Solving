#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, ans;
vector <int> assignment[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	priority_queue <int, vector <int>> pq;
	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		assignment[d].push_back(w);
	}
	for (int i = 1000; i >= 1; i--) {
		while (assignment[i].size()) {
			pq.push(assignment[i].back());
			assignment[i].pop_back();
		}
		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}