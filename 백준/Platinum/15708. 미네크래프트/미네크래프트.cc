#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long N, T, P, t, ans;
long long rocks[100000];

struct lower {
	bool operator() (long long A, long long B) {
		return A > B;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T >> P;
	priority_queue <long long, vector <long long>> pq;
	for (int i = 0; i < N; i++)	cin >> rocks[i];
	for (int i = 0; i < N; i++) {
		if (i == 0) t += rocks[i];
		else t += (P + rocks[i]);
		pq.push(rocks[i]);
		while (pq.size() && t > T) {
			t -= pq.top();
			pq.pop();
		}
		ans = max(ans, (long long)pq.size());
	}
	cout << ans;
	return 0;
}