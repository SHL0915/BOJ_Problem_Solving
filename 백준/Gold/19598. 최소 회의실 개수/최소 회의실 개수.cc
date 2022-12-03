#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int N, ans;
pair<int, int> arr[100000];
priority_queue <int, vector<int>, cmp> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		arr[i] = { A,B };
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		while (pq.size()) {
			if (pq.top() <= arr[i].first) pq.pop();
			else break;
		}
		pq.push(arr[i].second);
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
	return 0;
}