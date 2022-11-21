#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct func {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int N, ans = 1;
pair<int, int> lecture[100001];
priority_queue <int, vector<int>, func> pq;

bool cmp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first) return A.second < B.second;
	return A.first < B.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		lecture[A] = { B,C };
	}
	sort(lecture + 1, lecture + N + 1, cmp);	
	for (int i = 1; i <= N; i++) {
		pq.push(lecture[i].second);
		while (pq.size()) {
			if (pq.top() <= lecture[i].first) pq.pop();
			else break;
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
	return 0;
}