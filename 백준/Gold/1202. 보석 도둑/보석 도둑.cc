#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, jewel_idx;
priority_queue <long long> val;
pair<long long, long long> jewel[300000];
long long bag[300000];
long long ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int weight, value;
		cin >> weight >> value;
		jewel[i] = { weight, value };
	}
	for (int i = 0; i < K; i++) cin >> bag[i];	
	sort(jewel, jewel + N);
	sort(bag, bag + K);
	for (int i = 0; i < K; i++) {
		while (jewel[jewel_idx].first <= bag[i]) {
			val.push(jewel[jewel_idx].second);
			jewel_idx++;
		}
		if (val.size()) {
			ans += val.top();
			val.pop();
		}
	}
	cout << ans;
	return 0;
}