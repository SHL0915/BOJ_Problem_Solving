#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


long long N, M, ans;
vector <pair<long long, long long>> people;
pair<long long, long long> arr[500001];
priority_queue <long long> pq;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		long long L, R;
		cin >> L >> R;
		people.push_back({ R, L });
	}
	sort(people.begin(), people.end());
	for (int i = 0; i < M; i++) {
		long long P, X;
		cin >> P >> X;
		arr[i] = { P,X };
	}
	sort(arr, arr + M);
	for (int i = M - 1; i >= 0; i--) {
		while (people.size()) {
			if (people.back().first >= arr[i].first) {
				pq.push(people.back().second);
				people.pop_back();
			}
			else break;
		}
		while (pq.size()) {
			if (arr[i].second == 0) break;
			if (pq.top() <= arr[i].first) {
				pq.pop();
				arr[i].second--;
				ans++;
			}
			else pq.pop();			
		}
	}
	cout << ans;
	return 0;
}