#include <iostream>
#include <queue>
using namespace std;

int N, P, cnt;
priority_queue<int> pq[7];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		int line, fret;
		cin >> line >> fret;
		if (pq[line].size() == 0) {
			pq[line].push(fret);
			cnt++;
		}
		else if (pq[line].top() == fret) continue;
		else if (pq[line].top() < fret) {
			pq[line].push(fret);
			cnt++;
		}
		else {
			while (pq[line].size()) {
				if (pq[line].top() <= fret) break;
				pq[line].pop();
				cnt++;
			}
			if (pq[line].size() == 0 || pq[line].top() < fret) {
				pq[line].push(fret);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}