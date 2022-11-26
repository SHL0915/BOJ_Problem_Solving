#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator() (int A, int B) {
		if (A % 10 == 0 && B % 10 == 0) return A > B;
		else if (A % 10 == 0) return false;
		else if (B % 10 == 0) return true;
		else return A > B;
	}
};

int N, M, ans;
int arr[1000];
priority_queue<int, vector<int>, cmp> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == 10) ans++;
		pq.push(arr[i]);
	}
	for (int i = 0; i < M; i++) {
		while (pq.size()) {
			if (pq.top() <= 10) pq.pop();
			else break;
		}
		if (pq.size() == 0) continue;
		int t = pq.top();
		pq.pop();
		if (t == 20) ans += 2;
		else {
			ans++;
			pq.push(t - 10);
		}
	}
	cout << ans;
	return 0;
}