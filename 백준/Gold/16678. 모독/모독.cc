#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int N;
int arr[100001];
priority_queue <int, vector<int>, cmp> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	int now = 0;
	long long cnt = 0;
	while (pq.size()) {
		if (pq.top() <= now) pq.pop();
		else if (pq.top() == now + 1) {
			pq.pop();
			now++;
		}
		else {
			cnt += (pq.top() - (now + 1));
			pq.pop();
			now++;
		}
	}
	cout << cnt;
	return 0;
}