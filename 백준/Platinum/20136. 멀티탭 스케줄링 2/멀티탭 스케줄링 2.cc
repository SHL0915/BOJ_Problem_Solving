#include <iostream>
#include <queue>
using namespace std;

const int INF = 1234567890;

int N, K, cnt, ans;
int arr[500001];
int mark[500001];
deque <int> tool[500001];
priority_queue<pair<int, int>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		tool[arr[i]].push_back(i);
	}
	for (int i = 1; i <= K; i++) tool[i].push_back(INF);
	for (int i = 0; i < K; i++) {
		tool[arr[i]].pop_front();
		if (mark[arr[i]] == 1) {
			pq.push({ tool[arr[i]].front(), arr[i] });
			continue;
		}
		if (cnt < N) {
			pq.push({ tool[arr[i]].front(), arr[i] });
			mark[arr[i]] = 1;
			cnt++;
		}
		else {
			mark[pq.top().second] = 0;
			pq.pop();
			pq.push({ tool[arr[i]].front(), arr[i] });
			mark[arr[i]] = 1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}