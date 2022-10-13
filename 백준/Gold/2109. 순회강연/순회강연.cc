#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// priority_queue를 사용한 풀이

int N, ans;
vector <int> lecture[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	priority_queue <int, vector <int>> pq;
	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;
		lecture[d].push_back(p);
	}
	for (int i = 10000; i >= 1; i--) {
		while (lecture[i].size()) {
			pq.push(lecture[i].back());
			lecture[i].pop_back();
		}
		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}