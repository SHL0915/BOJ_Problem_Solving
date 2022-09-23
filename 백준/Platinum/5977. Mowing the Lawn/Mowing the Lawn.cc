#include <iostream>
#include <queue>
using namespace std;

/* i - K <= j <= i 인 j 중, 부분합 sum[i] - sum[j] + memo[j - 1]의 최대값을 찾는다.
priority queue에 memo[j-1] - sum[j]의 최대값을 저장하여 해결 */

long long N, K, i;
long long memo[100000];
long long sum[100000];
long long input;

struct pqData {
	long long val;
	long long index;
};

struct cmp {
	bool operator()(pqData a, pqData b) {
		return a.val < b.val;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue <pqData, deque<pqData>, cmp> pq;
	cin >> N >> K >> sum[0];
	for (i = 1; i < N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	memo[0] = sum[0];
	pq.push({ -sum[0],0 });
	for (i = 1; i < N; i++) {
		input = memo[i - 1] - sum[i];
		pq.push({ input,i });
		while (pq.size() && pq.top().index < i - K)
			pq.pop();
		if (i < K) memo[i] = sum[i]; // 연속된 소의 수가 K보다 적은 경우
		else memo[i] = sum[i] + pq.top().val; // sum[i] + deque에 저장된 최댓값
	}
	cout << memo[N - 1];
	return 0;
}