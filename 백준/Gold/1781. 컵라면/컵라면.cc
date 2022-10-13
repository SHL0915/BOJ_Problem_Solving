#include <iostream>
#include <algorithm>
#include <queue>;
using namespace std;

int N, ans;
vector <int> arr[200001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	priority_queue <int, vector <int>> pq;
	for (int i = 0; i < N; i++) {
		int deadline, ramyun;
		cin >> deadline >> ramyun;
		arr[deadline].push_back(ramyun);
	}
	for (int i = N; i >= 1; i--) {
		while (arr[i].size()) {
			pq.push(arr[i].back());
			arr[i].pop_back();
		}
		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}