#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int N;
priority_queue <int, vector<int>, cmp> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int A;
		cin >> A;
		if (pq.size() < N) pq.push(A);
		else {
			if (A > pq.top()) {
				pq.pop();
				pq.push(A);
			}
		}
	}
	cout << pq.top();
	return 0;
}