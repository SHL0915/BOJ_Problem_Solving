#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator () (long long A, long long B) {
		return A > B;
	}
};

int N, M;
priority_queue <long long, vector <long long>, cmp> pq;
long long card;
long long ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card;
		pq.push(card);
	}
	for (int i = 0; i < M; i++) {
		long long A, B;
		A = pq.top();
		pq.pop();
		B = pq.top();
		pq.pop();
		pq.push(A + B);
		pq.push(A + B);
	}
	while (pq.size()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}